#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int n;
    int arr[300000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), comp);
    int last = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != last) {
            last = arr[i];
            count += 1;
        }
    }
    printf("%d", count);
}