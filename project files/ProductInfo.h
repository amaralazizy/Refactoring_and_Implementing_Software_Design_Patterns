#pragma once
#include <iostream>
using namespace std;

class ProductInfo
{
protected:
    string name;
    string description;
    double price;
public:
    virtual ~ProductInfo (){}
    virtual string getName() const=0;
    virtual string getDescription() const = 0;
    virtual  double getPrice() const = 0;
    virtual  void setName(const string& newName) = 0;
    virtual  void setDescription(const string& newDescription) = 0;
    virtual  void setPrice(double newPrice) = 0;
};

