//
// Created by NoteBook on 23/05/2023.
//

#ifndef ONLINE_SHOP2_UTILS_H
#define ONLINE_SHOP2_UTILS_H
#include <vector>

using std::vector;
// Note: This is a singleton
class Utils {
    static Utils* instance;

public:
    static Utils* getInstance();
    int getValidNum(int to, int from = 0) const;

};


#endif //ONLINE_SHOP2_UTILS_H
