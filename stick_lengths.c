#include <stdio.h>
#include <stdlib.h>

#define ABS(a) ((a) > 0 ? (a) : (a) * -1)

int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int arr[250000];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), comp);
    int mid = arr[n / 2];
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += ABS(arr[i] - mid);
    }
    printf("%lld", total);
    return 0;
}