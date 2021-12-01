#ifndef __data__
#define __data__

int const intSize = sizeof(int);
int const BIRD = 1;
int const FISH = 2;
int const BEAST = 3;

int const animalSize = 2 * sizeof(int) + 255 * sizeof(char);
int const maxSize = 10000 * animalSize;

// Functions

// Read from file
void Read(void* c, int* len, FILE* input);
// Random container
void GetRandom(void* c, int* len, int size);
// Print to file
void PrintOut(void* c, int len, FILE* output);
// Sort
extern void QuickSort(void* animals, int cnt, int i = 0);

#endif
