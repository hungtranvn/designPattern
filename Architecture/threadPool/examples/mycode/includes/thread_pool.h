#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include <memory>
#include <future>
#include <functional>

template<typename F, typename... Args>
using JobReturnType = typename std::result_of<F(Args...)>::type;

// define job priorities
enum class Priority : size_t {
  Normal,
  High,
  Critical
};

Class ThreadPool {
public:
  // constructor take the default number of hardware threads
  ThreadPool(size_t threadCount = std::thread::hardware_concurrency());
  ThreadPool(ThreadPool&&) = default;
  ThreadPool& operator=(ThreadPool&&) = default;
  
  ~ThreadPool();

  ThreadPool(const ThreadPool&) = delete;
  ThreadPool& operator=(const ThreadPool&) = delete;
  
  template<typename F, typename... Args>
  auto schedule(Priority jobType, F&& f, Args&&... args) \
  -> std::future<JobReturnType<F, Args...>>;
  
  template<typename F, typename... Args>
  auto schedule(F&& f, Args&&.. args) \
  -> std::future<JobReturnType<F, Args...>>;

private:
  void add_job(std::function<void()> job, Priority jobType);
  class Pimpl;
  std::unique_ptr<Pimpl> _impl;
};
#endif // _THREAD_POOL_H
