#pragma once
#include "Animal.h";

class Bird : public IAnimal {
public:
    bool isMigratory;
    Bird(std::string n, int w, bool isM) {
        name = n;
        weightG = w;
        isMigratory = isM;
    }
    std::string typeName() override {
        return "Bird";
    }
    std::string paramToStr() override {
        if (isMigratory)
            return "is migratory";
        else
            return "is not migratory";
    }
};