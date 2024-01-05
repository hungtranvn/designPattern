#include <NormalUser.h>

std::list<User> NormalUser::getBenificiaries() const {
    return this->m_benificiaries;
}

NormalUser::NormalUser(std::string userName, int age, std::string gender, \
                std::string userId, E_ID_TYPE idType, std::list<User> benificiaries) :
            User(userName, age, gender, userId, idType) {
    this->m_benificiaries = benificiaries;
}