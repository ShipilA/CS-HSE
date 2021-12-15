#pragma once
#include "PirateCrew.h"

void wait_thread(void) {
    time_t stop_time = clock() + WAIT_TIME;
    while (clock() < stop_time) {}
}

void* SearchTreasure(void* vptr_args) {
    int index = *(int*)vptr_args;
    printf("Searching for the treasure at coordinates: %d %d\n", index / M, index % M);
    if (OUTPUT != NULL)
        fprintf(OUTPUT, "Searching for the treasure at coordinates: %d %d\n", index / M, index % M);
    // Imitating timeconsuming searching
    wait_thread();
    if (ISLAND_TREASURE_MAP[index]) {
        printf("The treasure was found at coordinates: %d %d!\n", index / M, index % M);
        if (OUTPUT != NULL)
            fprintf(OUTPUT, "The treasure was found at coordinates: %d %d!\n", index / M, index % M);
    }
    else {
        printf("At coordinates: %d %d - there is no treasure:(\n", index / M, index % M);
        if (OUTPUT != NULL)
            fprintf(OUTPUT, "At coordinates: %d %d - there is no treasure:(\n", index / M, index % M);
    }
    return (void*)(ISLAND_TREASURE_MAP[index]);
}

void SilverLeads()
{
    printf("\nPirates are on the island! They are going to find the treasure.\n\n");
    if (OUTPUT != NULL)
        fprintf(OUTPUT, "\nPirates are on the island! They are going to find the treasure.\n\n");
    TREASURE_FOUND = 0;
    pthread_t pirates[PIRATES_CNT];
    int number[PIRATES_CNT];
    CNT_CHECKED = 0;
    while (!TREASURE_FOUND) {
        int stop_pirate = PIRATES_CNT - 1;
        for (int i = 0; i < PIRATES_CNT && CNT_CHECKED < N * M; ++i) {
            printf("Silver is sending pirate number %d to look for the treasure at coordinates: %d %d\n", i, CNT_CHECKED / M, CNT_CHECKED % M);
            if (OUTPUT != NULL)
                fprintf(OUTPUT, "Silver is sending pirate number %d to look for the treasure at coordinates: %d %d\n", i, CNT_CHECKED / M, CNT_CHECKED % M);
            number[i] = CNT_CHECKED;
            ++CNT_CHECKED;
            if (CNT_CHECKED == N * M) {
                stop_pirate = i;
            }
            pthread_create(&pirates[i], NULL, SearchTreasure, &number[i]);
        }
        for (int i = 0; i <= stop_pirate; ++i) {
            bool* search_res;
            pthread_join(pirates[i], (void**)&search_res);
            TREASURE_FOUND = TREASURE_FOUND || search_res;
        }
    }
}
