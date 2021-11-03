from Bird import Bird
from Beast import Beast
from Fish import Fish
import QSort
import sys
import time


def read_animals(animals, input_file):
    with open(input_file, 'r') as f_in:
        for line in f_in:
            t, label, weight, param = line.split()
            weight = int(weight)
            if t == "Bird":
                if param == "true":
                    animals.append(Bird(label, weight, True))
                else:
                    animals.append(Bird(label, weight, False))
            elif t == "Fish":
                animals.append(Fish(label, weight, param))
            elif t == "Beast":
                animals.append(Beast(label, weight, param))
            else:
                print("Incorrect format in input file.\n Every line should be: \"Bird/Beast/Fish Name Weight(in grams) "
                      "parameter\",\nfor Bird the parameter should be true or false (if the bird is migratory, true),"
                      "for Beast the parameter should be predator, herbivore or insectivorous,"
                      "for Fish the parameter should be river, sea or lake - the place of living.\n")
                exit(0)
            if len(animals) > 10000:
                print("Memory limit : the container shouldn't have more than 10 000 animals.\n")
                exit(0)


def main(input_file, output):
    animals = []
    read_animals(animals, input_file)
    with open(output, 'w') as f_out:
        for animal in animals:
            f_out.write(animal.to_string() + "\n")
        f_out.write("\nThere are" + str(len(animals)) + "animals in the container.\n")
        QSort.quick_sort(animals, len(animals))
        f_out.write("\nThe result of the quick sort:\n")
        for animal in animals:
            f_out.write(animal.to_string() + "\n")


if __name__ == '__main__':
    start = time.time()
    if len(sys.argv) != 3:
        print("Incorrect command line. Necessary to do: input file name, output file name\n")
        exit(0)
    else:
        main(sys.argv[1], sys.argv[2])
    print("Program execution time:", time.time() - start, "seconds")
