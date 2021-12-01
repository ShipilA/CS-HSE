#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "animal.h"

int main(int argc, char* argv[]) {
    clock_t start = clock();
    unsigned char container[maxSize];
    // Amount of elements
    int len = 0;

    if (argc == 4 && !strcmp(argv[1], "-f")) {
        FILE* input = fopen(argv[2], "r");
        Read(container, &len, input);
    }
    else if (argc == 4 && !strcmp(argv[1], "-n")) {
        int cnt = atoi(argv[2]);
        if ((cnt < 1) || (cnt > 10000)) {
            printf("Incorrect numer of animals = %d. Set 0 < number <= 10000\n",
                cnt);
            exit(2);
        }
        GetRandom(container, &len, cnt);
    }
    else {
        std::cout << "Incorrect comman line. Necessary to do: "
            "-f input_file_name, output_file_name\n"
            "or -rnd amount_of_elements, output_file_name\n";
        exit(1);
    }
    FILE* output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Impossible to open the output file, error.\n");
        exit(1);
    }
    PrintOut(container, len, output);
    fprintf(output, "\nThere are %d animals in the container.\n\n", len);
    // Sort the animals and then write it to the output file.
    QuickSort(container, len);
    fprintf(output, "\nThe result of the quick sort:\n\n");
    PrintOut(container, len, output);
    fclose(output);
    // Measure time.
    clock_t end = clock();
    printf("Program execution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
