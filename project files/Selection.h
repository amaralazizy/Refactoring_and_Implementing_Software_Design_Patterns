#ifndef ONLINE_SHOP2_SELECTION_H
#define ONLINE_SHOP2_SELECTION_H

#include <map>
#include <string>
#include "ObjectPool.h"
#include "user.h"
#include <functional>

using namespace std;

class Selection{
    map<int, pair<string, function<void(User**)>>> choices;
    int largestNum;
    Selection();
public:
    friend class ObjectPool<Selection>;
    void addChoice(const string choice, function<void(User**)> callback = [](User** user){}, const int num = 0);

    void handleUserChoice(User** user);

    void initialize();

    void reset();
};

#endif //ONLINE_SHOP2_SELECTION_H
