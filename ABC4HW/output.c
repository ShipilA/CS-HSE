#include <stdio.h>
#include "animal.h"

double Function(void* animal);

bool PrintAnimal(void *a, FILE *output) {
    if ((int*)animal == 1) {
        fprintf(output, "Bird  %s weights %d gramms and ", (const char *)(animal + 2 * intSize), (int*)(animal));
        if ((int*)(animal + intSize) == 1)
            fprintf(output, "is migratory\n");
        else
            fprintf(output, "is not migratory\n");
    }
    else if ((int*)animal == 2) {
        fprintf(output, "Fish %s weights %d gramms and ", (const char*)(animal + 2 * intSize), (int*)(animal));
        if ((int*)(animal + intSize) == 1)
            fprintf(output, "lives in river\n");
        else if ((int*)(animal + intSize) == 2)
            fprintf(output, "lives in sea\n");
        else
            fprintf(output, "lives in lake\n");
    }
    else if ((int*)animal == 3) {
        fprintf(output, "Beast %s weights %d gramms and ", (const char*)(animal + 2 * intSize), (int*)(animal));
        if ((int*)(animal + intSize) == 1)
            fprintf(output, "is a predator\n");
        else if ((int*)(animal + intSize) == 2)
            fprintf(output, "is herbivore\n");
        else
            fprintf(output, "is insectivorous\n");
    }
}


void PrintOut(void* c, int len, FILE* output) {
    void *tmp = c;
    for (int i = 0; i < len; i++) {
        PrintAnimal(tmp, output);
        tmp = tmp + animalSize;
    }
}