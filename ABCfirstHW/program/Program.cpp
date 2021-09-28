#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Bird.h"
#include "Fish.h"
#include "Animal.h"
#include "Beast.h"

void QuickSort(IAnimal* animals[], int cnt) {
    int i = 0, j = cnt - 1;
    IAnimal* temp, * center;
    center = animals[cnt >> 1];
    do {
        while (animals[i] < center)
            ++i;
        while (animals[j] < center)
            --j;
        if (i <= j) {
            temp = animals[i];
            animals[i] = animals[j];
            animals[j] = temp;
            ++i;
            --j;
        }
    } while (i <= j);
    if (j > 0)
        QuickSort(animals, j);
    if (cnt > i)
        QuickSort(animals + i, cnt - i);
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Incorrect comman line. Necessary to do: "
            "input file name, output file name\n");
        exit(1);
    }
    IAnimal* animals[10000];
    int i = 0;
    FILE* input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Impossible to open the input file, error.\n");
        exit(1);
    }
    char type[255], label[255], param[255];
    int weight;
    while (fscanf(input, "%s %s %d %s", type, label, &weight, param) == 4) {
        if (strcmp(type, "Bird") == 0) {
            if (strcmp(param, "true") == 0)
                animals[i] = new Bird(label, weight, true);
            else if (strcmp(param, "false") == 0)
                animals[i] = new Bird(label, weight, false);
        }
        else if (strcmp(type, "Beast") == 0) {
            if (strcmp(param, "predator") == 0)
                animals[i] = new Beast(label, weight, predator);
            else if (strcmp(param, "herbivore") == 0)
                animals[i] = new Beast(label, weight, herbivore);
            else if (strcmp(param, "insectivorous") == 0)
                animals[i] = new Beast(label, weight, insectivorous);
        }
        else if (strcmp(type, "Fish") == 0) {
            if (strcmp(param, "river") == 0)
                animals[i] = new Fish(label, weight, river);
            else if (strcmp(param , "sea") == 0)
                animals[i] = new Fish(label, weight, sea);
            else if (strcmp(param, "lake") == 0)
                animals[i] = new Fish(label, weight, lake);
        }
        else {
            printf("Wrong format in input file.\n Every line should be: \"Bird/Beast/Fish Name Weight(in gramms) parametor\",\n"
                "for Bird the parametor should be true or false (if the bird is migratory, true),"
                "for Beast the parametor should be predator, herbivore or insectivorous,"
                "for Fish the parametor should be river, sea or lake - the place of living.\n");
            exit(1);
        }
        ++i;
        if (i > 10000) {
            printf("Memory limit: the container shouldn't have more than 10 000 animals.\n");
            exit(1);
        }
    }
    fclose(input);
    FILE* output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Impossible to open the output file, error.\n");
        exit(1);
    }
    for (int j = 0; j < i; ++j) {
        fprintf(output, "%s %s weights %d gramms and %s\n", animals[j]->typeName(), animals[j]->name, animals[j]->weightG, animals[j]->paramToStr());
    }
    fprintf(output, "\nThere are %d animals in the container.\n\n", i);
    QuickSort(animals, i);
    fprintf(output, "\nThe result of the quick sort:\n\n");
    for (int j = 0; j < i; ++j) {
        fprintf(output, "%s %s weights %d gramms and %s\n", animals[j]->typeName(), animals[j]->name, animals[j]->weightG, animals[j]->paramToStr());
    }
    fclose(output);
}
