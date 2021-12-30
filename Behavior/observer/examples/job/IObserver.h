#ifndef _I_OBSERVER_H_
#define _I_OBSERVER_H_

#include "JobPost.h"

class IObserver {
public:
  virtual void onJobPosted(const JobPost& job) = 0;
};

#endif // _I_OBSERVER_H_
