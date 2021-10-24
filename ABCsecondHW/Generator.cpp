#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/// <summary>
/// Get a random string.
/// </summary>
/// <param name="len">The lenght of the string.</param>
/// <returns>Random string.</returns>
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

/// <summary>
/// The main function gets the output file name and generates a test to the file.
/// </summary>
/// <param name="argv">File for the test.</param>
int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Incorrect comman line. Necessary to do: "
            " file name (the file will be input for the program and output for the generator).\n");
        exit(1);
    }
    // Try to open the file.
    FILE* output = fopen(argv[1], "w");
    if (output == NULL) {
        printf("Impossible to open the output file, error.\n");
        exit(1);
    }
    int n;
    do {
        printf("Please, enter an amount of elements (integer from 0 to 10 000):\n");
    } while (scanf("%d", &n) != 1 || n < 0 || n > 10000);
    srand(time(NULL));
    // Generate a random element for each element of the container.
    for (int j = 0; j < n; ++j) {
        int cl = rand() % 3, strLen = rand() % 15 + 1;
        const char* name = RandString(strLen);
        if (cl == 1) {
            int m = rand() % 100000;
            if (rand() % 2)
                fprintf(output, "Bird %s %d true\n", name, m);
            else
                fprintf(output, "Bird %s %d false\n", name, m);
        }
        else if (cl == 2) {
            int m = rand() % 5000000;
            if (rand() % 2)
                fprintf(output, "Fish %s %d river\n", name, m);
            else {
                if (rand() % 2)
                    fprintf(output, "Fish %s %d sea\n", name, m);
                else
                    fprintf(output, "Fish %s %d lake\n", name, m);
            }
        }
        else {
            int m = rand() % 50000000;
            if (rand() % 2)
                fprintf(output, "Beast %s %d predator\n", name, m);
            else {
                if (rand() % 2)
                    fprintf(output, "Beast %s %d herbivore\n", name, m);
                else
                    fprintf(output, "Beast %s %d insectivorous\n", name, m);
            }
        }
    }
    fclose(output);
    // Lett the user know that the test was generated.
    printf("Generated successfully.\n");
}
