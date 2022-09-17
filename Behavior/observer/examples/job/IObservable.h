#ifndef _I_OBSERVABLE_H_
#define _I_OBSERVABLE_H_

#include "JobPost.h"
#include "IObserver.h"

class IObservable {
public:
  virtual void attach(IObserver& observer) = 0;
  virtual void addJob(const JobPost& jobPosting) = 0;
protected:
  virtual void notify(const JobPost& jobPosting) = 0;
};
#endif // _I_OBSERVABLE_H_
