#ifndef USER_H
#define USER_H
#include "medlog.h"
#include <string>

class User
{
private:
    string userName;
    int age;
    string email;
    int phoneNum;
    MedLogSystem log;

public:
    User();
    User(string _username, int _age, string _email, int _phoneNum); 

    void displayProfile();

    void saveUserData(string filename);    

    void loadUserData(string filename, string username);

    void startSession();

    void setName(string UserName);

    void setAge(int Age);

    void setEmail(string Email);

    void setPhoneNum(int PhoneNum);

    string getName();

    int getAge();

    string getEmail();

    int getPhoneNum();

};

#endif
