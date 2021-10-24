#pragma once
#include "Animal.h";

enum EatingType {
    predator, herbivore, insectivorous
};

class Beast : public IAnimal {
public:
    enum EatingType type;
    Beast(std::string n, int w, enum EatingType t) {
        name = n;
        weightG = w;
        type = t;
    }
    std::string typeName() override {
        return "Beast";
    }
    std::string paramToStr() override {
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