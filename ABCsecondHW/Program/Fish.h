#pragma once
#include "Animal.h";

enum PlaceOfLiving {
    river, sea, lake
};
class Fish : public IAnimal {
public:
    enum PlaceOfLiving place;
    Fish(std::string n, int w, enum PlaceOfLiving p) {
        name = n;
        weightG = w;
        place = p;
    }
    std::string typeName() override {
        return "Fish";
    }
    std::string paramToStr() override {
        if (place == river)
            return "lives in river";
        if (place == sea)
            return "lives in sea";
        else
            return "lives in lake";
    }
    ~Fish() {
        delete& place;
    }
};