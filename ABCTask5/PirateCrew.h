#pragma once

// Time for a pirate to search through one peace of island, it can be different, I choosed 1 second
int WAIT_TIME = CLOCKS_PER_SEC * 1;
// CNT_CHECKED - the last not checked area (the same as the amount of checked areas), NxM - size of the island, PIRATES_CNT - the amount of pirates
int CNT_CHECKED, N, M, PIRATES_CNT;
// ISLAND_TREASURE_MAP - array as map of the island (true if treasure is here, false if not), TREASURE_FOUND - indicates that Silver knows where the treasure is
bool* ISLAND_TREASURE_MAP, TREASURE_FOUND;
FILE* OUTPUT;

void wait_thread(void);

void* SearchTreasure(void* vptr_args);

void SilverLeads();
