#include <AdminUser.h>

std::string AdminUser::getVaccineCenter() const {
    return this->m_vaccineCenter;
}

AdminUser::AdminUser(std::string userName, int age, std::string gender, \
                std::string userId, E_ID_TYPE idType, Center vaccineCenter) : 
            User(userName, age, gender, userId, idType) {
    this->m_vaccineCenter = vaccineCenter;
}