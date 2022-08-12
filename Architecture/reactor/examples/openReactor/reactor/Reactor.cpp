#include "Reactor.h"
#include <assert.h>

namespace reactor
{

void
Reactor::dispatch_reactor_event(const EventHandlerIoDemuxer::EventData &event,
                                bool &is_stop_event)
{
  if (event.type < EventHandlerIoDemuxer::EVENT_USER)
    return;

  std::unordered_map<io_handle_t, EventHandler *>::iterator it =
      handlers_.find(event.io_handle);

  if (it == handlers_.end())
    return;

  switch (event.type)
  {
    case EVENT_TIMEOUT_ADD:
    {
      uint32_t timeout_msec = (uint64_t)(event.data);

      timer_.register_timeout(timeout_msec, it->second);
      return;
    }
    case EVENT_TIMEOUT_DEL:
    {
      timer_.remove_timeout(it->second);
      return;
    }
    case EVENT_STOP:
    {
      is_stop_event = true;
      return;
    }
  }
}

void
Reactor::dispatch_demuxer_event_io(const EventHandlerIoDemuxer::EventData &event)
{
  if (event.type > EventHandlerIoDemuxer::EVENT_CLOSE)
    return;

  std::unordered_map<io_handle_t, EventHandler *>::iterator it =
      handlers_.find(event.io_handle);

  if (it == handlers_.end())
  {
    demuxer_.remove_all_events(event.io_handle, nullptr, false);
    return;
  }

  EventHandler &handler = *(it->second);

  switch (event.type)
  {
    case EventHandlerIoDemuxer::EVENT_READ:
    {
      handler.handle_input(this);
      return;
    }
    case EventHandlerIoDemuxer::EVENT_WRITE:
    {
      demuxer_.remove_write_event(handler.io_handle_, nullptr, false);
      handler.handle_output(this);
      return;
    }
    case EventHandlerIoDemuxer::EVENT_ERROR:
    {
      int       error = 0;
      socklen_t errlen = sizeof(error);
      if (getsockopt(handler.io_handle_, SOL_SOCKET, SO_ERROR, (void *)&error, &errlen) == 0)
      {
        if (error != 0)
        {
          handler.handle_error(this, error, std::strerror(error));
          return;
        }
      }

      handler.handle_error(this, errno, std::strerror(errno));
      return;
    }
    case EventHandlerIoDemuxer::EVENT_CLOSE:
    {
      if (handle_close_call_.count(handler.io_handle_) > 0)
        return;

      handle_close_call_.insert(handler.io_handle_);
      handler.handle_close(this);
      return;
    }
  }
}

void
Reactor::dispatch_demuxer_event_result(const EventHandlerIoDemuxer::EventData &event)
{
  if (event.type <= EventHandlerIoDemuxer::EVENT_CLOSE)
    return;

  EventHandler *handler = event.data;
  if (handler == nullptr)
    return;

  switch (event.type)
  {
    case EventHandlerIoDemuxer::EVENT_REGISTER_READ:
    {
      ++handler_count_;
      handlers_.emplace(std::make_pair(event.io_handle, handler));
      handler->io_handle_ = event.io_handle;

      handler->handle_registered(this, event.io_handle);
      if (handler != reactor_handler_ && reactor_handler_ != nullptr)
        reactor_handler_->reactor_handle_registered_handler(this, handler);

      return;
    }
    case EventHandlerIoDemuxer::EVENT_REMOVE_ALL:
    {
      if (handlers_.count(event.io_handle) == 0)
        return;

      timer_.remove_timeout(handler);
      handlers_.erase(event.io_handle);
      handle_close_call_.erase(event.io_handle);

      handler->handle_removed(this);
      if (handler != reactor_handler_ && reactor_handler_ != nullptr)
        reactor_handler_->reactor_handle_removed_handler(this, handler);

      --handler_count_;
      return;
    }
  }
}

void
Reactor::run()
{
  stop_ = false;

  std::vector<EventHandlerIoDemuxer::EventData> events;
  events.reserve(10000);

  run_reactor_handler();

  while (true)
  {
    int32_t msec = 0;
    while ((msec = timer_.get_min_timeout_milliseconds()) == 0)
      run_timeout_handler();

    events.clear();
    demuxer_.wait(events, msec);

    // timeout
    if (events.size() == 0)
    {
      run_timeout_handler();
      continue;
    }

    if (dispatch(events) == true)
      break;
  }

  run_shutdown();

  stop_ = true;
}
}

