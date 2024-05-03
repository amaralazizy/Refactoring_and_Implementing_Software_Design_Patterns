#include "Utils.h"
#include<iostream>

using std::cout;
using std::cin;

Utils* Utils::getInstance(){
    if (instance == nullptr)
    {
        instance = new Utils();
    }
    return instance;
}

Utils* Utils::instance = nullptr;

int Utils::getValidNum(int to, int from) const{
    int val = -1;
    bool notValid = false;
    do{
        cin >> val;
        notValid = !(val >= from && val <= to);
        if(notValid)
            cout << "Please Enter a valid count in the range (from " << from << " to " << to << "): ";

    }while(notValid);
    return val;
}
