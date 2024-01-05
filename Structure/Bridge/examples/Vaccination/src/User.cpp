#include "User.h"

std::string User::getUserName() const {
    return this->m_userName;
}

std::string User::getUserId() const {
    return this->m_userId;
}

std::string User::getIdType() const {
    return this->m_idType;
}

std::string User::getIdNumber() const {
    return this->m_idNumber;
}

std::string User::getGender() const {
    return this->m_gender;
}

int User::getAge const {
    return this->m_age;
}

User::User(std::string userName, int age, std::string gender, std::string userId, E_ID_TYPE idType) {
    this->m_userName = userName; 
    this->m_age = age;
    this->m_gender = gender;
    this->m_idNumber = userId;
    this->m_idType = idType;
}

