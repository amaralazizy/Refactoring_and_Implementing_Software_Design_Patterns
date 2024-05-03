//
// Created by NoteBook on 23/05/2023.
//

#ifndef ONLINE_SHOP2_OBJECTPOOL_H
#define ONLINE_SHOP2_OBJECTPOOL_H

#include <vector>

template <typename T>
class ObjectPool {
    std::vector<T*> pool;
    static ObjectPool<T>* instance;

    ObjectPool() {}
public:
    T* acquireObject();
    void releaseObject(T* obj);
    static ObjectPool<T>* getInstance();
};


//#include "ObjectPool.h"

template <typename T>
T* ObjectPool<T>::acquireObject() {
    if (pool.empty()) {
        T* obj = new T();
        obj->initialize();
        return obj;
    }
    else {
        T* obj = pool.back();
        pool.pop_back();
        obj->reset();
        return obj;
    }
}

template <typename T>
void ObjectPool<T>::releaseObject(T* obj) {
    pool.push_back(obj);
}

template <typename T>
ObjectPool<T>* ObjectPool<T>::getInstance() {
    if (instance == nullptr)
    {
        instance = new ObjectPool<T>;
    }
    return instance;
}

template <typename T>
ObjectPool<T>* ObjectPool<T>::instance = nullptr;



#endif //ONLINE_SHOP2_OBJECTPOOL_H
