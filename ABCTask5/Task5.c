#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "PirateCrew.cpp"

int main(int argc, char* argv[]) {
    // Reading input data
    if (argc != 2 && argc != 3) {
        printf("Incorrect comman line. Necessary to do: "
            "input file name\nor\n input file name and output file name");
        exit(1);
    }
    FILE* input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Impossible to open the input file, error.\n");
        exit(1);
    }
    if (fscanf(input, "%d %d %d", &N, &M, &PIRATES_CNT) != 3 || N <= 0 || M <= 0 || PIRATES_CNT <= 0) {
        printf("Incorrect input file, it should contain 3 positive integers: the height, the width of the island and the amount of pirates.\n");
        exit(1);
    }
    fclose(input);
    if (argc == 3)
        OUTPUT = fopen(argv[2], "w");
    else
        OUTPUT = NULL;
    if (OUTPUT == NULL) {
        printf("Impossible to open the input file, so the results will be only in the command line.\n");
    }
    // Generating island map
    ISLAND_TREASURE_MAP = malloc(sizeof(bool) * M * N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            ISLAND_TREASURE_MAP[i * M + j] = false;
    }
    printf("Do you want to generate treasure location randomly?\nWrite y, if yes.\nOtherwise write any another symbol and two numbers (x and coordinates).\n");
    char answer;
    scanf("%c", &answer);
    if (answer == 'y' || answer == 'Y') {
        srand(time(NULL));
        ISLAND_TREASURE_MAP[rand() % (M * N)] = 1;
        printf("Coordinates of the treasure were generated randomly.\n");
        if (OUTPUT != NULL)
            fprintf(OUTPUT, "Coordinates of the treasure were generated randomly.\n");
    } else {
        printf("Write two integer numbers (x and y coordinates of the treasure).\n");
        int x, y;
        while (scanf("%d %d", &x, &y) != 2 || x < 0 || x > N || y < 0 || y > M) {
            printf("Incorrect input! Write two integer numbers (x and y coordinates of the treasure), which are in the island boundaries.\n");
        }
        if (OUTPUT != NULL)
            fprintf(OUTPUT, "Coordinates of the treasure were chosen by user: %d %d.\n", x, y);
        ISLAND_TREASURE_MAP[x * M + y] = 1;
    }
    // Using clock to compare the program execution time with different inputs
    clock_t start = clock();
    // Silver leads the pirates to find the treasure
    SilverLeads();
    // Freeing space (free func for every malloc)
    free(ISLAND_TREASURE_MAP);
    printf("\nAfter looking for treasure at %d coordinates, pirates found it.\n", CNT_CHECKED);
    if (OUTPUT != NULL)
        fprintf(OUTPUT, "\nAfter looking for treasure at %d coordinates, pirates found it.\n", CNT_CHECKED);
    // Executing time
    clock_t end = clock();
    printf("\nProgram execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    if (OUTPUT != NULL) {
        fprintf(OUTPUT, "\nProgram execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
        fclose(OUTPUT);
    }
    return 0;
}
