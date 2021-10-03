#pragma once
#include <stdio.h>
#include "Animal.h";

enum EatingType {
    predator, herbivore, insectivorous
};

class Beast : public IAnimal {
public:
    enum EatingType type;
    Beast (const char* n, int w, enum EatingType t) {
        strcpy(name, n);
        weightG = w;
        type = t;
    }
    const char* typeName() override {
        return "Beast";
    }
    const char* paramToStr() override {
        if (type == predator)
            return "is a predator";
        if (type == herbivore)
            return "is herbivore";
        else
            return "is insectivorous";
    }
    ~Beast() {
        delete& type;
    }
};