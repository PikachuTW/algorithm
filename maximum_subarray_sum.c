#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    long long sum = 0;
    long long maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > maxSum) maxSum = sum;
        if (sum < 0) sum = 0;
    }
    printf("%lld", maxSum);
    return 0;
}