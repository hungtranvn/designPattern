#include "JobSeeker.h"
#include "JobPosting.h"
#include "JobPost.h"

int main() {
  JobSeeker johnDoe("John Doe");
  JobSeeker janeDoe("Jane Doe");

  JobPosting jobPostings;
  jobPostings.attach(johnDoe);
  jobPostings.attach(janeDoe);

  jobPostings.addJob(JobPost("Software Engineer"));
  jobPostings.addJob(JobPost("Maketing Manager"));

  return 0;
}
