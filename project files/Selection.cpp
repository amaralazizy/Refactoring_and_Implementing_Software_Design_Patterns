//
// Created by NoteBook on 23/05/2023.
//

#include "Selection.h"
#include "Utils.h"
#include <map>
#include<iostream>

using std::string;
using std::map;
using std::cout;
using std::cin;

Selection::Selection():largestNum(0){}

void Selection::addChoice(const string choice, function<void(User**)> callback , const int num){
    int key = (num == 0) ? ++largestNum : num;
    choices.insert(make_pair(key , make_pair(choice, callback)));
}

void Selection::handleUserChoice(User** user) {
    cout << "Choose a Number:\n";
    for(auto i : choices){
        cout << "Press " << i.first << " to " << i.second.first << '\n';
    }

    Utils* util = Utils::getInstance();
    int num = util->getValidNum(largestNum);
    choices[num].second(user);
}

void Selection::initialize() {}

void Selection::reset() {
    largestNum = 0;
    choices.clear();
}

