#include "thread_pool.h"

#include <thread>
#include <map>
#include <mutex>
#include <queue>
#include <string>
#include <vector>

class ThreadPool::Pimpl {
public:
  void init(size_t threadCount); // init the pool and start the threads
  void shut_down();
  void add_job(std::function<void()>&& job, Priority jobType);

private:
  bool _running = true;
  std::mutex _guard; // use while adding job or extracting one from queue
  std::conditional_variable _sleep;
  std::vector<std::thread> _workers;
  std::map<Priority, std::queue<std::function<void()>>, \
    std::greater<Priorityt>> _jobs;
};

ThreadPool::ThreadPool(size_t threadCount) : \
  _impl(std::make_unique<ThreadPool::Pimpl>()) {
  _impl->init(threadCount);
}

ThreadPool::~ThreadPool() {
  _impl->shut_down();
}

void ThreadPool::add_job(std::function<void()> job, Priority jobType) {
  _impl->add_job(std::move(job), jobType)
}

template <typename F, typename... Args>
auto ThreadPool::schedule(Priority jobType, F&& f, Args&&.. args) -> \
       std::future<JobReturnType<F, Args...>> {
  auto job = std::make_shared<std::packaged_task<JobReturnType<F, \
             Args...>()>>(
               std::bind(std::forward<F>(f), std::forward<Args>(args)...)
             );
  add_job([job] {(*job)();}, jobType);
  return job->get_future();
}

template <typename F, typename... Args>
auto ThreadPool::schedule(F&& f, Args&&... args) -> \
       std::future<JobReturnType<F, Args...>> {
         return schedule<Priority::Normal, std::forward<F>(f), \
           std::forward<Args>(args)...>;
       }

void ThreadPool::Pimpl::init(size_t threadCount) {
  _jobs[Priority::Normal] = {};
  _jobs[Priority::High] = {};
  _jobs[Priority::Critical] = {};

  _workers.reserve(threadCount);

  for (auto i = 0; i < threadCount; i++) {
    _workers.push_back(std::thread([this](){
      while (_running) {
      std::function<void()> job;
      {
        std::unique_lock<std::mutex> ul(_guard);
        _sleep.wait(ul, [this](){
          if (false == _running)
            return true;
          bool allQueuesEmpty = true;
          for (const auto& kvp : _jobs)
            allQueusesEmpty &= kvp.second.empty();
          return !allQueuesEmpty;
        });

        for (auto& kvp : _jobs) {
          auto& jobs = kvp.second;
          if (jobs.empty()) {
            continue;
          }
          jobs = std::move(jobs.front());
          job.pop();
          break;
        }
      }

      if (job != nullptr)
        job();
      }
    }));
  }
}

void ThreadPool:Pimpl::shut_down() {
  _running = false;
  _sleep.notify_all();

  for (auto& worker : _workers) {
    if (worker.joinable())
      worker.join();
  }
}

void ThreadPool::Pimpl::add_job(std::function<void()>&& job, Priority jobType) {
  std::unique_lock<std::mutex> ul(_guard);
  _jobs[jobType].emplace(std::move(job));
  _sleep.notify_one();
}
