#ifndef _JOB_POST_H_
#define _JOB_POST_H_

#include <string>

class JobPost {
public:
  JobPost(const std::string& title);
  const std::string& getTitle() const;
private:
  std::string title_;
};

#endif // _JOB_POST_H_
