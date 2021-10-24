#pragma once
#include <string>

class IAnimal {
public:
    std::string name;
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
    virtual std::string typeName() = 0;
    virtual std::string paramToStr() = 0;
    //virtual ~IAnimal() = 0;
};