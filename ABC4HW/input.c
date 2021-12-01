#include <stdio.h>
#include "animal.h"

bool InAnimal(void *a, FILE *input) {
    return fscanf(input, "%d%d%s", (int*)a, (int*)(a + intSize), (int*)(a + intSize * 2));
}

void Read(void* c, int* len, FILE* input) {
    void *tmp = c;
    while (!feof(input)) {
        if (InAnimal(tmp, input)) {
            tmp = tmp + animalSize;
            (*len)++;
        }
    }
}