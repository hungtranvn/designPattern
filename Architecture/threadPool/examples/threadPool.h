#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>

class ThreadPool
{
public:
  ThreadPool(size_t);
  template<class F, class... Args>
  auto enqueue(F&& f, Args&&... args)
    -> std::future<typename std::result_of<F(Args...)>::type>;
  ~ThreadPool();
private:
  std::vector<std::thread> workers;
  std::mutex queue_mutex;
  std::condition_variable condition;
  bool stop;
};
#endif // THREAD_POOL_H
