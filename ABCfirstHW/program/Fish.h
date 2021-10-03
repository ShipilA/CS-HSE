#pragma once
#include <stdio.h>
#include "Animal.h";

enum PlaceOfLiving {
    river, sea, lake
};

class Fish : public IAnimal {
public:
    enum PlaceOfLiving place;
    Fish(const char* n, int w, enum PlaceOfLiving p) {
        strcpy(name, n);
        weightG = w;
        place = p;
    }
    const char* typeName() override {
        return "Fish";
    }
    const char* paramToStr() override {
        if (place == river)
            return "lives in river";
        if (place == sea)
            return "lives in sea";
        else
            return "lives in lake";
    }
    ~Fish() {
        delete &place;
    }
};