from Animal import Animal
import enum


class EatingType(enum.Enum):
    predator = 1
    herbivore = 2
    insectivorous = 3


class Beast(Animal):
    def __init__(self, name, w, t):
        Animal.__init__(self, name, w)
        for eat_t in EatingType:
            if t == eat_t.name:
                self.type = eat_t

    def type_name(self):
        Animal.type_name(self)
        return "Beast"

    def to_string(self):
        Animal.to_string(self)
        return "Beast " + self.name + " weight " + str(self.weight) + " grams and is " + self.type.name

