from Animal import Animal
import enum


class PlaceOfLiving(enum.Enum):
    river = 1
    sea = 2
    lake = 3


class Fish(Animal):
    def __init__(self, name, w, place):
        Animal.__init__(self, name, w)
        for pl in PlaceOfLiving:
            if place == pl.name:
                self.place = pl

    def type_name(self):
        Animal.type_name(self)
        return "Fish"

    def to_string(self):
        Animal.to_string(self)
        return "Fish " + self.name + " weight " + str(self.weight) + " grams and lives in " + self.place.name
