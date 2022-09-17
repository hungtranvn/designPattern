#ifndef _JOB_POSTING_H_
#define _JOB_POSTING_H_

#include "IObservable.h"
#include "IObserver.h"
#include "JobPost.h"
#include <vector>
#include <functional>

class JobPosting : public IObservable {
public:
  void attach(IObserver& observer) override;
  void addJob(const JobPost& jobPosting) override;
private:
  void notify(const JobPost& jobPosting) override;
  std::vector<std::reference_wrapper<IObserver>> observer_;
};
#endif // _JOB_POSTING_H_
