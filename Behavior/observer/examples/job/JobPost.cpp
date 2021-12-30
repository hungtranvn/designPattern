#include "JobPost.h"

JobPost::JobPost(const std::string& title) : title_ (title) {}

const std::string& JobPost::getTitle() const {
  return title_;
}
