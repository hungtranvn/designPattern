#include "JobSeeker.h"
#include "iostream"

void JobSeeker::onJobPosted(const JobPost& job) {
  std::cout << "Hi" << name_ << "! New job posted: " << job.getTitle() << \
    std::endl;
}
