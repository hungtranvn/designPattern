/*
 * Reactor.h
 *
 *  Created on: 2020. 2. 3.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_REACTOR_REACTOR_H_
#define OPEN_REACTOR_REACTOR_REACTOR_H_

#include <reactor/ReactorHandlerFactory.h>
#include <reactor/EventHandler.h>
#include <reactor/ObjectsTimer.h>
#include <reactor/IoHandleDemuxer.h>

#include <unordered_map>
#include <unordered_set>
#include <atomic>
#include <cerrno>
#include <cstring>

#include <assert.h>

namespace reactor
{

/***
 * @brief It acts as a dispatcher.
 */


class Reactor
{
public:
  using EventHandlerIoDemuxer = IoHandleDemuxer<EventHandler *, nullptr>;

  Reactor();
  bool  init(int32_t max_clients,
             size_t  max_events,
             ReactorHandlerFactory *factory = nullptr);

  bool  register_event_handler(EventHandler *handler, const io_handle_t &io_handle);
  bool  remove_event_handler  (EventHandler *handler);
  bool  register_writable     (EventHandler *handler);

  bool  set_timeout           (EventHandler *handler, const uint32_t &msec);
  bool  unset_timeout         (EventHandler *handler);

  void  run ();
  void  stop();

  size_t handler_count() const;

  ReactorHandler *reactor_handler();

private:
  enum
  {
    EVENT_TIMEOUT_ADD = EventHandlerIoDemuxer::EVENT_USER,
    EVENT_TIMEOUT_DEL,
    EVENT_STOP
  };

  bool dispatch                     (const std::vector<EventHandlerIoDemuxer::EventData> &events);
  void dispatch_reactor_event       (const EventHandlerIoDemuxer::EventData &event,
                                     bool &is_stop_event);
  void dispatch_demuxer_event_io    (const EventHandlerIoDemuxer::EventData &event);
  void dispatch_demuxer_event_result(const EventHandlerIoDemuxer::EventData &event);

  void run_timeout_handler();
  void run_reactor_handler();
  void run_shutdown();

private:
  // 추후 reactor의 오류 메세지등 처리하기 위해 이거 함.
  ReactorHandler        *reactor_handler_         = nullptr;
  ReactorHandlerFactory *reactor_handler_factory_ = nullptr;

private:
  std::unordered_map<io_handle_t, EventHandler *> handlers_;
  std::unordered_set<io_handle_t>                 handle_close_call_;

private:
  size_t                      handler_count_ = 0;
  ObjectsTimer<EventHandler>  timer_;
  EventHandlerIoDemuxer       demuxer_;
  std::atomic<bool>           stop_;
};

inline
Reactor::Reactor()
: handler_count_(0), stop_(false) {}

inline bool
Reactor::init(int32_t max_clients,
              size_t  max_events,
              ReactorHandlerFactory *factory)
{
  handler_count_ = 0;
  stop_ = false;

  reactor_handler_factory_ = factory;
  if (reactor_handler_factory_ != nullptr)
    ++max_clients;

  return demuxer_.init(max_clients, max_events);
}

inline bool
Reactor::register_event_handler(EventHandler *handler, const io_handle_t &io_handle)
{
  if (stop_.load() == true)
    return false;

  demuxer_.register_read_event(io_handle, handler, true);
  return true;
}

inline bool
Reactor::remove_event_handler(EventHandler *handler)
{
  if (stop_.load() == true)
    return false;

  demuxer_.remove_all_events(handler->io_handle_, handler, true);
  return true;
}

inline bool
Reactor::register_writable(EventHandler *handler)
{
  if (stop_.load() == true)
    return false;

  demuxer_.register_write_event(handler->io_handle_,
                                handler,
                                false);
  return true;
}

inline bool
Reactor::set_timeout(EventHandler *handler,
                     const uint32_t &msec)
{
  if (stop_.load() == true)
    return false;

  demuxer_.raise_user_event(EVENT_TIMEOUT_ADD,
                            handler->io_handle_,
                            (EventHandler *)((uint64_t)msec));
  return true;
}

inline bool
Reactor::unset_timeout(EventHandler *handler)
{
  if (stop_.load() == true)
    return false;

  demuxer_.raise_user_event(EVENT_TIMEOUT_DEL,
                            handler->io_handle_);
  return true;
}

inline size_t
Reactor::handler_count() const
{
  if (reactor_handler_ == nullptr)
    return handler_count_;

  return handler_count_ - 1;
}

inline ReactorHandler *
Reactor::reactor_handler()
{
  return reactor_handler_;
}

inline void
Reactor::stop()
{
  demuxer_.raise_user_event(EVENT_STOP);
}

inline bool
Reactor::dispatch(const std::vector<EventHandlerIoDemuxer::EventData> &events)
{
  bool is_stop_event = false;
  for (const EventHandlerIoDemuxer::EventData &event : events)
  {
    dispatch_reactor_event       (event, is_stop_event);
    dispatch_demuxer_event_io    (event);
    dispatch_demuxer_event_result(event);
  }

  return is_stop_event;
}

inline void
Reactor::run_timeout_handler()
{
  std::deque<std::unordered_set<EventHandler *>> objects =
      timer_.get_timeout_objects();

  for (std::unordered_set<EventHandler *> handlers : objects)
    for (EventHandler *handler : handlers)
      handler->handle_timeout(this);
}

inline void
Reactor::run_reactor_handler()
{
  if (reactor_handler_factory_ == nullptr)
    return;

  reactor_handler_ = reactor_handler_factory_->create(this);
  if (reactor_handler_ == nullptr)
    return;

  if (reactor_handler_->init() == false)
  {
    reactor_handler_->reactor_handle_error(this, errno,
                                           std::string("Initialization failed ") + std::strerror(errno));
    reactor_handler_factory_->destroy(this, reactor_handler_);
    reactor_handler_ = nullptr;
  }
  else
  {
    this->register_event_handler(reactor_handler_,
                                 reactor_handler_->io_handle_);
  }
}

inline void
Reactor::run_shutdown()
{
  for (std::pair<const io_handle_t, EventHandler *> &item : handlers_)
  {
    timer_.remove_timeout(item.second);
    demuxer_.remove_all_events(item.second->io_handle_, nullptr, false);
    item.second->handle_shutdown(this);
  }

  if (reactor_handler_          != nullptr &&
      reactor_handler_factory_  != nullptr)
  {
    reactor_handler_factory_->destroy(this, reactor_handler_);
    reactor_handler_ = nullptr;
  }
}

}

#endif // OPEN_REACTOR_REACTOR_REACTOR_H_









