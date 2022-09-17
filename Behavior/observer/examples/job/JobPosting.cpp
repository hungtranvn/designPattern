#include "JobPosting.h"

void JobPosting::attach(IObserver& observer) {
  observer_.push_back(observer);
}

void JobPosting::addJob(const JobPost& jobPosting) {
  notify(jobPosting);
}

void JobPosting::notify(const JobPost& jobPosting) {
  for(IObserver& observer : observer_)
    observer.onJobPosted(jobPosting);
}
