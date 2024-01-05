#ifndef _ADMIN_USER_H_
#define _ADMIN_USER_H_
#include <User.h>

class Center {
private:
    std::string m_centerId;
    std::string m_address;
    int m_noVaccines;
    int m_noGiven;
public:
    std::string getCenterAddress() const {
        return this->m_address;
    }

    std::string getCenterId() const {
        return this->m_centerId;
    }

    int getNoVaccines() const {
        return this->m_noVaccines;
    }

    int getNoGiven() const {
        return this->m_noGiven;
    }

    Center(String centerId, String address, int noOfVaccines, int noOfDozesGiven) : \
    m_centerId(centerId), m_address(address), m_noVaccine(noOfVaccines), m_noGiven(noOfDozesGiven) {
    }
};

class AdminUser : public User {
private:
    std::string m_vaccineCenter;
public:
    std::list<User> getVaccineCenter() const;
    AdminUser(std::string userName, int age, std::string gender, \
                std::string userId, E_ID_TYPE idType, Center vaccineCenter);
};
#endif // _ADMIN_USER_H_