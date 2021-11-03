def quick_sort(animals, cnt, i=0):
    if cnt <= 1:
        return
    j = cnt - 1
    center = animals[cnt >> 1]
    while i <= j:
        while i + 1 < len(animals) and animals[i] < center:
            i += 1
        while j > 0 and animals[j] < center:
            j -= 1
        if i <= j:
            animals[i], animals[j] = animals[j], animals[i]
            i += 1
            j -= 1
    if j > 0:
        quick_sort(animals, j)
    if cnt > i:
        quick_sort(animals, cnt - i, i)
