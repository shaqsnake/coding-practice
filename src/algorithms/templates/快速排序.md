```c++
void quicksort(int q[], int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, p = q[(l + r) >> 1];

    while (i < j) {
        do ++i; while (q[i] < p);
        do --j; while (q[j] > p);
        if (i < j) swap(q[i], q[j]);
        else break;
    }

    quicksort(q, l, j), quicksort(q, j+1, r);
    return;
}
```