#include <stdio.h>

int main(void) {
    int n = 0;
    int arr[300000] = {0};
    scanf("%d", &n);
    long long moves = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        int dif = arr[i - 1] - arr[i];
        if (dif > 0) {
            moves += dif;
            arr[i] = arr[i - 1];
        }
    }
    printf("%lld", moves);
    return 0;
}