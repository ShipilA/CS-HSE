#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int WAIT_TIME = CLOCKS_PER_SEC * 1;
int cnt, n, m, pirates_cnt;
bool * treasure, treasure_found;

void wait_thread(void) {
    time_t stop_time = clock() + WAIT_TIME;
    while (clock() < stop_time) {}
}

void* SearchTreasure(void* vptr_args) {
    int index = *(int*)vptr_args;
    printf("Searching for the treasure at coordinates: %d %d\n", index / m, index % m);
    wait_thread();
    if (treasure[index]) {
        printf("The treasure was found at coordinates: %d %d!\n", index / m, index % m);
    }
    else {
        printf("At coordinates: %d %d - there is no treasure:(\n", index / m, index % m);
    }
    return (void*)(treasure[index]);
}

int main(int argc, char* argv[]) {
    // Using clock to compare the program execution time with different inputs
    clock_t start = clock();
    if (argc != 2) {
        printf("Incorrect comman line. Necessary to do: "
            "input file name\n");
        exit(1);
    }
    FILE* input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Impossible to open the input file, error.\n");
        exit(1);
    }
    if (fscanf(input, "%d %d %d", &n, &m, &pirates_cnt) != 3) {
        printf("Incorrect input file, it should contain 3 integers: the height, the width of the island and the amount of pirates.\n");
        exit(1);
    }
    fclose(input);
    treasure = malloc(sizeof(bool) * m * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            treasure[i * m + j] = false;
    }
    printf("Do you want to generate treasure location randomly?\nWrite y, if yes.\nOtherwise write any another symbol and two numbers (x and coordinates).\n");
    char answer;
    scanf("%c", &answer);
    if (answer == 'y' || answer == 'Y') {
        srand(time(NULL));
        treasure[rand() % (m * n)] = 1;
        printf("Coordinates of the treasure were generated randomly.\n");
    } else {
        printf("Write two integer numbers (x and y coordinates of the treasure).\n");
        int x, y;
        while (scanf("%d %d", &x, &y) != 2 && (x < 0 || x > n || y < 0 || y > m)) {
            printf("Incorrect input! Write two integer numbers (x and y coordinates of the treasure), which are in the island boundaries.\n");
        }
        treasure[x * m + y] = 1;
    }
    printf("\nPirates are on the island! They are going to find the treasure.\n\n");
    treasure_found = 0;
    pthread_t pirates[pirates_cnt];
    int number[pirates_cnt];
    cnt = 0;
    while (!treasure_found) {
        for (int i = 0; i < pirates_cnt; ++i) {
            printf("Silver is sending pirate number %d to look for the treasure at coordinates: %d %d\n", i, cnt / m, cnt % m);
            number[i] = cnt;
            ++cnt;
            pthread_create(&pirates[i], NULL, SearchTreasure, &number[i]);
        }
        for (int i = 0; i < pirates_cnt; ++i) {
            bool* search_res;
            pthread_join(pirates[i], (void**)&search_res);
            treasure_found = treasure_found || search_res;
        }
    }
    free(treasure);
    printf("\nAfter looking for treasure at %d coordinates, pirates found it.\n", cnt);
    clock_t end = clock();
    printf("Program execution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);
}
