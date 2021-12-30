#ifndef _JOB_SEEKER_H_
#define _JOB_SEEKER_H_

#include "IObserver.h"
#include "JobPost.h"
#include <string>

class JobSeeker : public IObserver {
public:
  JobSeeker(const std::string& name) : name_(name) {}
  void onJobPosted(const JobPost& job) override;

private:
  std::string name_;
};
#endif // _JOB_SEEKER_H_
