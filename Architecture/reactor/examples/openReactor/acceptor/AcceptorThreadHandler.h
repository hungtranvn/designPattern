/*
 * AcceptorThreadHandler.h
 *
 *  Created on: 2020. 8. 3.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_TCP_ACCEPTOR_ACCEPTTHREADHANDLER_H_
#define OPEN_REACTOR_TCP_ACCEPTOR_ACCEPTTHREADHANDLER_H_

#include <chrono>
#include <stdint.h>

namespace reactor
{

class AcceptorThread;

class AcceptorThreadHandler
{
protected:
  virtual ~AcceptorThreadHandler() {}
  virtual void handle_registered() {}
  virtual void handle_timeout   () {}
  virtual void handle_shutdown  () { delete this; }

protected:
  void set_timeout  (const uint32_t &msec);
  void unset_timeout();

protected:
  virtual int32_t get_min_timeout() const;

private:
  mutable bool setting_timeout_ = false;
  std::chrono::steady_clock::time_point timeout_;
  friend class AcceptorThread;
};

inline void
AcceptorThreadHandler::set_timeout(const uint32_t &msec)
{
  timeout_ = std::chrono::steady_clock::now() + std::chrono::milliseconds(msec);
  setting_timeout_ = true;
}

inline void
AcceptorThreadHandler::unset_timeout()
{
  setting_timeout_ = false;
}

inline int32_t
AcceptorThreadHandler::get_min_timeout() const
{
  if (setting_timeout_ == false)
    return -1;

  int32_t remain_msec =
      std::chrono::duration_cast<std::chrono::milliseconds>
        (timeout_ - std::chrono::steady_clock::now()).count();

  if (remain_msec < 0)
    return 0;

  return remain_msec;
}

}

#endif /* COMMON_LIB_HTTP_REACTOR_HTTP_RSERVER_ACCEPTORTHREADHANDLER_H_ */
