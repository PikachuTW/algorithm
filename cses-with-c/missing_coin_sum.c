#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), comp);
    long long sum = 1;
    for (int i = 0; i < n; i++) {
        if (sum < arr[i]) break;
        sum += arr[i];
    }
    printf("%lld", sum);
    return 0;
}