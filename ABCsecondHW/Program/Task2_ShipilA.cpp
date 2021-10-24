#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Bird.h"
#include "Fish.h"
#include "Animal.h"
#include "Beast.h"

/// <summary>
/// Quick sort for array of animals
/// </summary>
/// <param name="animals">Array of animals</param>
/// <param name="cnt">The amount of elements in the array</param>
void QuickSort(std::vector<IAnimal*> &animals, int cnt, int i = 0) {
    if (cnt <= 1)
        return;
    int j = cnt - 1;
    IAnimal* temp, * center;
    // Choose the central element to compare others with it.
    center = animals[cnt >> 1];
    do {
        while (i + 1 < animals.size() && animals[i] < center)
            ++i;
        while (j > 0 && animals[j] < center)
            --j;
        // Swap elements if needed.
        if (i <= j) {
            temp = animals[i];
            animals[i] = animals[j];
            animals[j] = temp;
            ++i;
            --j;
        }
    } while (i <= j);
    // Recursive call.
    if (j > 0)
        QuickSort(animals, j);
    if (cnt > i)
        QuickSort(animals, cnt - i, i);
}

/// <summary>
/// The main function: reads the file describing container, sorts and writes it.
/// </summary>
/// <param name="argv">Input and output files names</param>
/// <returns></returns>
int main(int argc, char* argv[]) {
    // Using clock to compare the program execution time with different inputs
    clock_t start = clock();
    if (argc != 3) {
        std::cout << "Incorrect comman line. Necessary to do: "
            "input file name, output file name\n";
        exit(1);
    }
    std::vector<IAnimal*> animals(0);
    int i = 0;
    std::ifstream input(argv[1]);
    // For reading container.
    std::string type, label, param;
    int weight = 0;
    // Trying to read one element of the container.
    while (input >> type >> label >> weight >> param) {
        // Choosing the type of the element.
        if (type == "Bird") {
            if (param == "true")
                animals.push_back(new Bird(label, weight, true));
            else if (param == "false")
                animals.push_back(new Bird(label, weight, false));
        }
        else if (type == "Beast") {
            if (param == "predator")
                animals.push_back(new Beast(label, weight, predator));
            else if (param == "herbivore")
                animals.push_back(new Beast(label, weight, herbivore));
            else if (param == "insectivorous")
                animals.push_back(new Beast(label, weight, insectivorous));
        }
        else if (type == "Fish") {
            if (param == "river")
                animals.push_back(new Fish(label, weight, river));
            else if (param == "sea")
                animals.push_back(new Fish(label, weight, sea));
            else if (param == "lake")
                animals.push_back(new Fish(label, weight, lake));
        }
        else {
            std::cout << "Wrong format in input file.\n Every line should be: \"Bird/Beast/Fish Name Weight(in gramms) parametor\",\n"
                "for Bird the parametor should be true or false (if the bird is migratory, true),"
                "for Beast the parametor should be predator, herbivore or insectivorous,"
                "for Fish the parametor should be river, sea or lake - the place of living.\n";
            exit(1);
        }
        ++i;
        if (i > 10000) {
            std::cout << "Memory limit : the container shouldn't have more than 10 000 animals.\n";
            exit(1);
        }
    }
    // Writting to the output file.
    input.close();
    std::ofstream output;
    output.open(argv[2]);
    for (int j = 0; j < i; ++j) {
        output << animals[j]->typeName() << " " << animals[j]->name << " weights " << animals[j]->weightG << " gramms and " << animals[j]->paramToStr() << "\n";
    }
    output << "\nThere are " << i << " animals in the container.\n\n";
    // Sort the animals and then write it to the output file.
    QuickSort(animals, i);
    output << "\nThe result of the quick sort:\n\n";
    for (int j = 0; j < i; ++j) {
        output << animals[j]->typeName() << " " << animals[j]->name << " weights " << animals[j]->weightG << " gramms and " << animals[j]->paramToStr() << "\n";
    }
    output.close();
    // Measure time.
    clock_t end = clock();
    std::cout << "Program execution time: " << ((double)end - start) / CLOCKS_PER_SEC << " seconds";
}
