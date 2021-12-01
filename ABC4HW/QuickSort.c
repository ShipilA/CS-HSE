void QuickSort(void* animals[], int cnt) {
    int i = 0, j = cnt - 1;
    void* temp, * center;
    // Choose the central element to compare others with it.
    center = animals[cnt >> 1];
    do {
        while (Function(animals[i]) < Function(center) + 1e-16)
            ++i;
        while (Function(animals[j]) < Function(center) + 1e-16)
            --j;
        // Swap elements if needed.
        if (i <= j) {
            temp = animals[i];
            animals[i] = animals[j];
            animals[j] = temp;
            ++i;
            --j;
        }
    } while (i <= j);
    // Recursive call.
    if (j > 0)
        QuickSort(animals, j);
    if (cnt > i)
        QuickSort(animals + i, cnt - i);
}