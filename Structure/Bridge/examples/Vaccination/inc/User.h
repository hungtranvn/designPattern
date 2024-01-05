#ifndef _USER_H_
#define _USER_H_
#include <string.h>
typedef enum {
    AADHAAR_CARD,
    VOTER_ID,
    DRIVING_LICENSE,
    PAN_CARD
} E_ID_TYPE;

class User {
private:
    int m_age;
    std::string m_gender;
    std::string m_idNumber;
    std::string m_userId;
    E_ID_TYPE m_idType;
    std::string m_userName;
public:
    std::string getUserName() const;
    std::string getUserId() const;
    E_ID_TYPE getIdType() const;
    std::string getIdNumber() const;
    std::string getGender() const;
    int getAge() const;
    User(std::string userName, int age, std::string gender, std::string userId, E_ID_TYPE idType);
};

#endif // _USER_H_