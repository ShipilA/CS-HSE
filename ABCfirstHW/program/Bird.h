#pragma once
#include <stdio.h>
#include "Animal.h";

class Bird : public IAnimal {
public:
    bool isMigratory;
    Bird(const char* n, int w, bool isM) {
        strcpy(name, n);
        weightG = w;
        isMigratory = isM;
    }
    const char* typeName() override {
        return "Bird";
    }
    const char* paramToStr() override {
        if (isMigratory)
            return "is migratory";
        else
            return "is not migratory";
    }
};