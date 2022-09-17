/*
 * IoHandleDemux.h
 *
 *  Created on: 2020. 2. 1.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_REACTOR_IOHANDLEDEMUXER_H_
#define OPEN_REACTOR_REACTOR_IOHANDLEDEMUXER_H_

#include <reactor/DefinedType.h>

#include <unordered_map>
#include <utility>
#include <atomic>
#include <vector>
#include <mutex>
#include <thread>

#include <unistd.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <string.h>

namespace reactor
{

template<typename USER_DATA_T, USER_DATA_T default_value>
class IoHandleDemuxer
{
public:
  IoHandleDemuxer()  {}
  ~IoHandleDemuxer() { if (epoll_events_ != nullptr) free(epoll_events_); }

  typedef enum
  {
    EVENT_WAIT_ERROR  = -1,
    EVENT_READ        = 1,
    EVENT_WRITE,
    EVENT_ERROR,
    EVENT_CLOSE,

    EVENT_REGISTER_ALL   = 10,
    EVENT_REGISTER_READ,
    EVENT_REGISTER_WRITE,
    EVENT_REGISTER_ERROR,

    EVENT_REMOVE_READ  = 20,
    EVENT_REMOVE_WRITE,
    EVENT_REMOVE_ERROR,
    EVENT_REMOVE_ALL,

    EVENT_USER = 100
  } RECV_EVENT;

  class EventData
  {
  public:
    EventData() {}
    EventData(const int32_t     &p_type,
              const io_handle_t &p_io_handle,
              USER_DATA_T       p_data = default_value)
    : type      (p_type),
      io_handle (p_io_handle),
      data      (p_data) {}
    virtual ~EventData() {}

    int32_t     type      = -1;
    io_handle_t io_handle = INVALID_IO_HANDLE;
    USER_DATA_T data;
  };

  bool init                 (const int32_t      &max_size         = 1024,
                             const size_t       &epoll_max_events = 10);

  void register_read_event  (const io_handle_t  &io_handle,
                             USER_DATA_T        user_data,
                             const bool         &return_event);

  void register_write_event (const io_handle_t  &io_handle,
                             USER_DATA_T        user_data,
                             const bool         &return_event);

  void register_error_event (const io_handle_t  &io_handle,
                             USER_DATA_T        user_data,
                             const bool         &return_event);

  void register_all_events  (const io_handle_t  &io_handle,
                             USER_DATA_T        user_data,
                             const bool         &return_event);

  void remove_read_event    (const io_handle_t  &io_handle,
                             USER_DATA_T        user_data,
                             const bool         &return_event);

  void remove_write_event   (const io_handle_t  &io_handle,
                             USER_DATA_T        user_data,
                             const bool         &return_event);

  void remove_error_event   (const io_handle_t  &io_handle,
                             USER_DATA_T        user_data,
                             const bool         &return_event);

  void remove_all_events    (const io_handle_t  &io_handle,
                             USER_DATA_T        user_data,
                             const bool         &return_event);

  void close_io_handle      (const io_handle_t  &io_handle,
                             USER_DATA_T        user_data,
                             const bool         &return_event);

  bool raise_user_event     (const int32_t      &user_defined_event_type,
                             const io_handle_t  &io_handle = INVALID_IO_HANDLE,
                             USER_DATA_T        user_data = default_value);

  std::vector<EventData>
  wait(const int32_t &timeout_msec = -1);

  int
  wait(std::vector<EventData> &return_events,
       const int32_t         &timeout_msec = -1);

private:

  class CtrlEventData : public EventData
  {
  public:
    CtrlEventData() {}
    CtrlEventData(const int32_t     &p_type,
                  const io_handle_t &p_io_handle,
                  USER_DATA_T       p_data,
                  const bool        &p_return_value)
    : EventData   (p_type, p_io_handle, p_data),
      return_value(p_return_value) {}

    virtual ~CtrlEventData() {}
    bool return_value = false;
  };

  int           pipe_ctrl_event_recv_ = INVALID_IO_HANDLE;
  int           pipe_ctrl_event_send_ = INVALID_IO_HANDLE;
  CtrlEventData pipe_ctrl_events_buffer[100000];
  std::vector<CtrlEventData> wait_thread_events_;

  private:
  void raise_event        (const int32_t     &event_type,
                           const io_handle_t &io_handle,
                           USER_DATA_T       user_data,
                           const bool        &return_event);

  void process_ctrl_events(std::vector<EventData>            &return_events,
                           const std::vector<CtrlEventData>  &ctrl_events);

  void process_ctrl_event (std::vector<EventData> &return_events,
                           const CtrlEventData    &event);

  void add_epoll_event    (const int32_t &event_type, const io_handle_t &io_handle);
  void del_epoll_event    (const int32_t &event_type, const io_handle_t &io_handle);
  void del_epoll_events   (const io_handle_t &io_handle);

  public:
  std::unordered_map<io_handle_t, struct epoll_event> epoll_events_by_io_handle_;

  private:
  std::thread::id     wait_thread_id_   = std::this_thread::get_id();
  size_t              epoll_max_events_ = 1000;
  int32_t             epoll_fd_         = -1;
  struct epoll_event *epoll_events_     = nullptr;
};

template<typename USER_DATA_T, USER_DATA_T default_value> bool
IoHandleDemuxer<USER_DATA_T, default_value>::init(const int32_t &max_size,
                                                  const size_t  &epoll_max_events)
{
  epoll_fd_ = epoll_create(max_size+1);
  if (epoll_fd_ < 0)
    return false;

  int pipe_ctrl_fd[2];
  if (pipe(pipe_ctrl_fd) < 0)
    return false;

  epoll_max_events_ = epoll_max_events;
  pipe_ctrl_event_recv_  = pipe_ctrl_fd[0];
  pipe_ctrl_event_send_  = pipe_ctrl_fd[1];

  epoll_events_by_io_handle_.reserve(max_size);
  epoll_events_ = (struct epoll_event *)calloc(sizeof(struct epoll_event), epoll_max_events);

  wait_thread_events_.reserve(max_size);

  add_epoll_event(EVENT_READ, pipe_ctrl_event_recv_);
  return true;
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::register_read_event(const io_handle_t &io_handle, USER_DATA_T user_data, const bool &return_event)
{
  raise_event(EVENT_REGISTER_READ, io_handle, user_data, return_event);
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::register_write_event(const io_handle_t &io_handle, USER_DATA_T user_data, const bool &return_event)
{
  raise_event(EVENT_REGISTER_WRITE, io_handle, user_data, return_event);
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::register_error_event(const io_handle_t &io_handle, USER_DATA_T user_data, const bool &return_event)
{
  raise_event(EVENT_REGISTER_ERROR, io_handle, user_data, return_event);
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::register_all_events(const io_handle_t &io_handle, USER_DATA_T user_data, const bool &return_event)
{
  raise_event(EVENT_REGISTER_ALL, io_handle, user_data, return_event);
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::remove_read_event(const io_handle_t &io_handle, USER_DATA_T user_data, const bool &return_event)
{
  raise_event(EVENT_REMOVE_READ, io_handle, user_data, return_event);
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::remove_write_event(const io_handle_t &io_handle, USER_DATA_T user_data, const bool &return_event)
{
  raise_event(EVENT_REMOVE_WRITE, io_handle, user_data, return_event);
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::remove_error_event(const io_handle_t &io_handle, USER_DATA_T user_data, const bool &return_event)
{
  raise_event(EVENT_REMOVE_ERROR, io_handle, user_data, return_event);
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::remove_all_events(const io_handle_t &io_handle, USER_DATA_T user_data, const bool &return_event)
{
  raise_event(EVENT_REMOVE_ALL, io_handle, user_data, return_event);
}

template<typename USER_DATA_T, USER_DATA_T default_value> bool
IoHandleDemuxer<USER_DATA_T, default_value>::raise_user_event(const int32_t     &user_defined_event_type,
                                                              const io_handle_t &io_handle,
                                                              USER_DATA_T       user_data)
{
  if (user_defined_event_type < EVENT_USER)
    return false;

  raise_event(user_defined_event_type, io_handle, user_data, true);
  return true;
}

template<typename USER_DATA_T, USER_DATA_T default_value>
std::vector<typename IoHandleDemuxer<USER_DATA_T, default_value>::EventData>
IoHandleDemuxer<USER_DATA_T, default_value>::wait(const int32_t &timeout_msec)
{
  std::vector<EventData> events;
  wait(events, timeout_msec);
  return events;
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::raise_event(const int32_t     &event_type,
                                                         const io_handle_t &io_handle,
                                                         USER_DATA_T       user_data,
                                                         const bool        &return_event)
{
  // if it is another thread, it sends an event to the pipe.
  if (std::this_thread::get_id() != wait_thread_id_)
  {
    CtrlEventData event_data(event_type, io_handle, user_data, return_event);

    ssize_t ignored __attribute__((unused)) =
        ::write(pipe_ctrl_event_send_, &event_data, sizeof(CtrlEventData));

    return;
  }

  wait_thread_events_.emplace_back(event_type, io_handle, user_data, return_event);
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::process_ctrl_events(std::vector<EventData>           &return_events,
                                                                 const std::vector<CtrlEventData> &ctrl_events)
{
  for (const CtrlEventData &event : ctrl_events)
    process_ctrl_event(return_events, event);
}

#define INIT_EPOLL_EVENT_VALUE (EPOLLHUP|EPOLLRDHUP)

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::add_epoll_event(const int32_t     &event_type,
                                                             const io_handle_t &io_handle)
{
  int32_t epoll_event = 0;
  switch (event_type)
  {
    case EVENT_READ : epoll_event = EPOLLIN;  break;
    case EVENT_WRITE: epoll_event = EPOLLOUT; break;
    case EVENT_ERROR: epoll_event = EPOLLERR; break;
    default: (void)event_type; break;
  }

  std::unordered_map<io_handle_t, struct epoll_event>::iterator it =
      epoll_events_by_io_handle_.find(io_handle);

  if (it != epoll_events_by_io_handle_.end())
  {
    struct epoll_event &event = it->second;
    if (event.events & epoll_event)
      return;

    event.events |= epoll_event;
    if (epoll_ctl(epoll_fd_, EPOLL_CTL_MOD, io_handle, &event) == -1)
    {
      event.events ^= epoll_event;
      return;
    }

    return;
  }

  struct epoll_event &event = epoll_events_by_io_handle_[io_handle];
  memset(&event, 0x00, sizeof(struct epoll_event));

  event.data.fd = io_handle;
  event.events  = INIT_EPOLL_EVENT_VALUE | epoll_event;
  if (epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, io_handle, &event) == -1)
  {
    epoll_events_by_io_handle_.erase(io_handle);
    return;
  }

  return;
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::del_epoll_event(const int32_t     &event_type,
                                                             const io_handle_t &io_handle)
{
  std::unordered_map<io_handle_t, struct epoll_event>::iterator it =
      epoll_events_by_io_handle_.find(io_handle);

  if (it == epoll_events_by_io_handle_.end())
    return;

  int32_t epoll_event = 0;
  switch (event_type)
  {
    case EVENT_READ : epoll_event = EPOLLIN;  break;
    case EVENT_WRITE: epoll_event = EPOLLOUT; break;
    case EVENT_ERROR: epoll_event = EPOLLERR; break;
    default: return;
  }

  struct epoll_event &event = it->second;

  if ((event.events ^ epoll_event) == INIT_EPOLL_EVENT_VALUE)
  {
    epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, io_handle, &event);
    epoll_events_by_io_handle_.erase(it);
    return;
  }

  event.events ^= epoll_event;
  epoll_ctl(epoll_fd_, EPOLL_CTL_MOD, io_handle, &event);

  return;
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::del_epoll_events(const io_handle_t &io_handle)
{
  std::unordered_map<io_handle_t, struct epoll_event>::iterator it =
      epoll_events_by_io_handle_.find(io_handle);

  if (it == epoll_events_by_io_handle_.end())
    return;

  struct epoll_event &event = it->second;
  epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, io_handle, &event);

  epoll_events_by_io_handle_.erase(it);
  return;
}

template<typename USER_DATA_T, USER_DATA_T default_value> void
IoHandleDemuxer<USER_DATA_T, default_value>::process_ctrl_event(std::vector<EventData> &return_events,
                                                                const CtrlEventData    &ctrl_events)
{
  switch (ctrl_events.type)
  {
    case EVENT_REGISTER_ALL  :
      add_epoll_event(EVENT_READ,   ctrl_events.io_handle);
      add_epoll_event(EVENT_WRITE,  ctrl_events.io_handle);
      add_epoll_event(EVENT_ERROR,  ctrl_events.io_handle);
      break;
    case EVENT_REGISTER_READ  : add_epoll_event (EVENT_READ,  ctrl_events.io_handle); break;
    case EVENT_REGISTER_WRITE : add_epoll_event (EVENT_WRITE, ctrl_events.io_handle); break;
    case EVENT_REGISTER_ERROR : add_epoll_event (EVENT_ERROR, ctrl_events.io_handle); break;
    case EVENT_REMOVE_READ    : del_epoll_event (EVENT_READ,  ctrl_events.io_handle); break;
    case EVENT_REMOVE_WRITE   : del_epoll_event (EVENT_WRITE, ctrl_events.io_handle); break;
    case EVENT_REMOVE_ERROR   : del_epoll_event (EVENT_ERROR, ctrl_events.io_handle); break;
    case EVENT_REMOVE_ALL     : del_epoll_events(ctrl_events.io_handle); break;
    default: (void)ctrl_events.type; break;
  }

  if (ctrl_events.return_value == true)
    return_events.emplace_back(ctrl_events);
}

template<typename USER_DATA_T, USER_DATA_T default_value> int
IoHandleDemuxer<USER_DATA_T, default_value>::wait(std::vector<EventData> &return_events,
                                                  const int32_t          &timeout_msec)
{
  wait_thread_id_ = std::this_thread::get_id();

  while (true)
  {
    if (wait_thread_events_.size() > 0)
    {
      process_ctrl_events(return_events, wait_thread_events_);
      wait_thread_events_.clear();

      if (return_events.size() > 0)
        return 0;
    }

    int32_t number_of_fd = epoll_wait(epoll_fd_, epoll_events_, epoll_max_events_, timeout_msec);
    if (number_of_fd < 0)
      return -1;

    for (int32_t index = 0; index < number_of_fd; ++index)
    {
      struct epoll_event &event     = epoll_events_[index];
      const io_handle_t  &io_handle = event.data.fd;

      if (io_handle == pipe_ctrl_event_recv_)
      {
        int32_t read_bytes = ::read(pipe_ctrl_event_recv_,
                                    pipe_ctrl_events_buffer,
                                    sizeof(pipe_ctrl_events_buffer));

        if (read_bytes <= 0)
          continue;

        for (size_t index = 0; index < (read_bytes/sizeof(CtrlEventData)); ++index)
          process_ctrl_event(return_events, pipe_ctrl_events_buffer[index]);

        continue;
      }

      // impossible
      // if (epoll_events_by_io_handle_.count(io_handle) == 0)
      //   continue;
      static char buff[1];
      if ((event.events & EPOLLIN) && (::recv(io_handle, &buff, 1, MSG_PEEK) > 0))
        return_events.emplace_back(EVENT_READ,  io_handle);

      if ((event.events & EPOLLOUT) && !(event.events & EPOLLERR))
        return_events.emplace_back(EVENT_WRITE, io_handle);

      if (event.events & EPOLLERR)
        return_events.emplace_back(EVENT_ERROR, io_handle);

      if ((event.events & EPOLLRDHUP) || (event.events & EPOLLHUP))
        return_events.emplace_back(EVENT_CLOSE, io_handle);
    }

    return 0;
  }
}

}

#endif /* OPEN_REACTOR_REACTOR_IOHANDLEDEMUXER_H_ */
