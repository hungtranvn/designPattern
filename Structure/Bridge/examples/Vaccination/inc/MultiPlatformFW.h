#ifndef _MULTI_PLATFORM_FW_H_
#define _MULTI_PLATFORM_FW_H_

#include <map>

class MultiPlatformFW {
    map<std::string, User> m_userDetail;
public:
    virtual boolean bookAppointment(std::string date , std::string userId , std::string slot , std::string centerId) = 0;

    virtual User getUserDetails(std::string userId) = 0;

    virtual void registerUser(std::user user) = 0;

    virtual void uploadVaccineCount(std::string userId, std::string date, int noOfVaccines) = 0;
}

#endif // _MULTI_PLATFORM_FW_H_