#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int n, x;
    scanf("%d%d", &n, &x);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), comp);
    int left = 0, right = n - 1;
    int ans = 0;
    while (left < right) {
        if (arr[left] + arr[right] <= x) {
            left += 1;
            right -= 1;
        } else {
            right -= 1;
        }
        ans += 1;
    }
    if (left == right) ans += 1;
    printf("%d", ans);
    return 0;
}