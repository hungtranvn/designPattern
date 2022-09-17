/*
 * ObjectTimer.h
 *
 *  Created on: 2020. 1. 31.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_REACTOR_OBJECTSTIMER_H_
#define OPEN_REACTOR_REACTOR_OBJECTSTIMER_H_

#include <reactor/DefinedType.h>

#include <map>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <deque>
#include <mutex>

namespace reactor
{

template<typename T>
class ObjectsTimer
{
public:
  ObjectsTimer(bool using_lock = false) : using_lock_(using_lock) {}

  int32_t get_min_timeout_milliseconds();

  int32_t register_timeout(const uint32_t &msec, T *object);

  void    remove_timeout  (T *object);

  std::deque<std::unordered_set<T *>>
          get_timeout_objects();

  bool    timeout_objects_exist() const;

private:
  std::deque<std::unordered_set<T *>>
          get_timeout_object_no_mutex();

  bool    timeout_objects_exist_no_mutex() const;

  int32_t get_min_timeout_milliseconds_no_mutex();

  void    remove_timeout_no_mutex(T *object);

private:
  std::map<std::chrono::steady_clock::time_point, std::unordered_set<T *>>  time_object_;
  std::unordered_map<T *, std::chrono::steady_clock::time_point>            object_time_;

  mutable std::mutex object_time_mutex_;
  bool using_lock_ = false;
};

template<typename T> int32_t
ObjectsTimer<T>::get_min_timeout_milliseconds_no_mutex()
{
  if (time_object_.size() == 0)
    return -1;

  int32_t min = std::chrono::duration_cast<std::chrono::milliseconds>(
      time_object_.begin()->first - std::chrono::steady_clock::now()).count();

  if (min < 0)
    return 0;

  return min;
}

template<typename T> int32_t
ObjectsTimer<T>::get_min_timeout_milliseconds()
{
  if (using_lock_ == false)
    return get_min_timeout_milliseconds_no_mutex();

  std::lock_guard<std::mutex> lock(object_time_mutex_);
  return get_min_timeout_milliseconds_no_mutex();
}

template<typename T> int32_t
ObjectsTimer<T>::register_timeout(const uint32_t  &msec, T *object)
{
  if (using_lock_ == false)
  {
    remove_timeout_no_mutex(object);

    object_time_[object] = std::chrono::steady_clock::now() + std::chrono::milliseconds(msec);
    time_object_[object_time_[object]].insert(object);

    return get_min_timeout_milliseconds_no_mutex();
  }

  std::lock_guard<std::mutex> lock(object_time_mutex_);

  remove_timeout_no_mutex(object);

  object_time_[object] = std::chrono::steady_clock::now() + std::chrono::milliseconds(msec);
  time_object_[object_time_[object]].insert(object);

  return get_min_timeout_milliseconds_no_mutex();
}

template<typename T> void
ObjectsTimer<T>::remove_timeout(T *object)
{
  if (using_lock_ == false)
  {
    remove_timeout_no_mutex(object);
    return;
  }

  std::lock_guard<std::mutex> lock(object_time_mutex_);
  remove_timeout_no_mutex(object);
}

template<typename T> std::deque<std::unordered_set<T *>>
ObjectsTimer<T>::get_timeout_objects()
{
  if (using_lock_ == false)
    return get_timeout_object_no_mutex();

  std::lock_guard<std::mutex> lock(object_time_mutex_);
  return get_timeout_object_no_mutex();
}

template<typename T> bool
ObjectsTimer<T>::timeout_objects_exist() const
{
  if (using_lock_ == false)
    return timeout_objects_exist_no_mutex();

  std::lock_guard<std::mutex> lock(object_time_mutex_);
  return timeout_objects_exist_no_mutex();
}

template<typename T> std::deque<std::unordered_set<T *>>
ObjectsTimer<T>::get_timeout_object_no_mutex()
{
  std::deque<std::unordered_set<T *>> timeout_objects;

  if (time_object_.size() == 0)
    return timeout_objects;

  std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();

  typename std::map<std::chrono::steady_clock::time_point,
                    std::unordered_set<T *>>::iterator it = time_object_.begin();

  while (it != time_object_.end())
  {
    if (it->first > now)
      break;

    for (T *object : it->second)
      object_time_.erase(object);

    timeout_objects.emplace_back(it->second);

    time_object_.erase(it++);
  }

  return timeout_objects;
}

template<typename T> bool
ObjectsTimer<T>::timeout_objects_exist_no_mutex() const
{
  std::deque<T *> timeout_objects;

  if (time_object_.size() == 0)
    return timeout_objects;

  std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();

  typename std::map<std::chrono::steady_clock::time_point,
    std::unordered_set<T *>>::iterator it = time_object_.begin();

  while (it != time_object_.end())
  {
    if (it->first > now)
      break;

    for (T *object : it->second)
      return true;
  }

  return false;
}

template<typename T> void
ObjectsTimer<T>::remove_timeout_no_mutex(T *object)
{
  if (object_time_.count(object) == 0)
    return;

  time_object_[object_time_[object]].erase(object);

  if (time_object_[object_time_[object]].size() == 0)
    time_object_.erase(object_time_[object]);

  object_time_.erase(object);
}

}

#endif /* OPEN_REACTOR_REACTOR_OBJECTSTIMER_H_ */

