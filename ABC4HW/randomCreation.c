#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "animal.h"

char* RandString(size_t len) {
    static char alph[] = "abcdefghijklmnopqrstuvwxyz";
    char* randString;
    // Getting memory space for the string.
    randString = (char*)malloc(sizeof(char) * (len + 1));
    // If successful, generate it
    if (randString) {
        // Choose every char randomly from the alphabet
        static int mod = (int)(sizeof(alph) - 1);
        static int key;
        for (int n = 0; n < len; n++) {
            key = rand() % mod;
            randString[n] = alph[key];
        }
        // Adding an end of string and changing the first letter to upper case.
        randString[len] = '\0';
        randString[0] = randString[0] + ('A' - 'a');
    }
    return randString;
}

bool RandomAnimal(void* a) {
    int k = rand() % 3 + 1;
    switch (k) {
    case 1:
        *((int*)a) = BIRD;
        *((int*)(a + intSize)) = rand() % 100000;
        *((const char *)(a + intSize * 2)) = RandString(rand() % 15 + 1);
        return true;
    case 2:
        *((int*)a) = FISH;
        *((int*)(a + intSize)) = rand() % 5000000;
        *((const char*)(a + intSize * 2)) = RandString(rand() % 15 + 1);
        return true;
    case 3:
        *((int*)a) = BEAST;
        *((int*)(a + intSize)) = rand() % 50000000;
        *((const char*)(a + intSize * 2)) = RandString(rand() % 15 + 1);
        return true;
    default:
        return false;
    }
}

void GetRandom(void* c, int* len, int size) {
    srand(time(NULL));
    void* tmp = c;
    while (*len < size) {
        if (RandomAnimal(tmp)) {
            tmp = tmp + animalSize;
            (*len)++;
        }
    }
}