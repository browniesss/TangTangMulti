#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Singleton
{
protected:
    Singleton() {}
public:
    Singleton(const Singleton& c) = delete;
    void operator=(const Singleton& c) = delete;

    static T& getInstance()
    {
        static T instance;
        return instance;
    }
};
