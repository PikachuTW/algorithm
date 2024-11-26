#include <stdio.h>

int main(void) {
    long long n;
    scanf("%lld", &n);
    long long sum = (1 + n) * n / 2;
    int k;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &k);
        sum -= k;
    }
    printf("%lld", sum);
    return 0;
}