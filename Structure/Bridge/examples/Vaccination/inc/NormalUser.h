#ifndef _NORMAL_USER_H_
#define _NORMAL_USER_H_
#include <User.h>

class NormalUser : public User {
private:
    std::list<User> m_benificiaries;
public:
    std::list<User> getBenificiaries() const;
    NormalUser(std::string userName, int age, std::string gender, \
                std::string userId, E_ID_TYPE idType, std::list<User> benificiaries);
};
#endif // _NORMAL_USER_H_