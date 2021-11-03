from abc import abstractmethod


class Animal:
    def __init__(self, name, w):
        self.name = name
        self.weight = w

    def __gt__(self, other):
        return self.func() + 1e-16 > other.func()

    def __lt__(self, other):
        return self.func() < 1e-16 + other.func()

    def func(self):
        ans = 0
        for i in range(len(self.name)):
            ans += ord(self.name[i])
        return ans / self.weight

    @abstractmethod
    def type_name(self):
        pass

    @abstractmethod
    def to_string(self):
        pass
