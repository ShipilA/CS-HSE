from Animal import Animal


class Bird (Animal):
    def __init__(self, name, w, is_m):
        Animal.__init__(self, name, w)
        self.is_migratory = is_m

    def type_name(self):
        Animal.type_name(self)
        return "Bird"

    def to_string(self):
        Animal.to_string(self)
        if self.is_migratory:
            return "Bird " + self.name + " weight " + str(self.weight) + " grams and is migratory"
        return "Bird " + self.name + " weight " + str(self.weight) + " grams and is not migratory"
