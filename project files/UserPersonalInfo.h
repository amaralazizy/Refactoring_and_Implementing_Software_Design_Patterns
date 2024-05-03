#pragma once
#include <iostream>
using namespace std;

class UserPersonalInfo
{
protected:
    string name;
    string email;
    string userAddress;
    string creditCardNumber;
public :
    virtual ~UserPersonalInfo(){}
    virtual string getName() const=0;

    virtual string getEmail() const = 0;
    virtual string getUserAddress() const = 0;
    virtual string getCreditCardNumber() const = 0;
    // Setter functions
    virtual void setName(const string newName) = 0;

    virtual void setEmail(const string& newEmail) = 0;

    virtual void setUserAddress(const string& newUserAddress) = 0;

    virtual void setCreditCardNumber(const string& newCreditCardNumber) = 0;
};

