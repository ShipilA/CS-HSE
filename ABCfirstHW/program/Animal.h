#pragma once
#include <stdio.h>
#include <string.h>

class IAnimal {
public:
    char name[255];
    int weightG;
    double Function() {
        double ans = 0;
        for (int i = 0; i < 255; ++i)
            ans += name[i];
        return ans / weightG;
    }
    bool operator < (IAnimal* a) {
        return this->Function() < a->Function() + 1e-16;
    }
    bool operator > (IAnimal* a) {
        return this->Function() + 1e-16 > a->Function();
    }
    virtual const char* typeName() = 0;
    virtual const char* paramToStr() = 0;
    virtual ~IAnimal() {
        delete[] name;
    }
};