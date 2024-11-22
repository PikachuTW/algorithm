#include <stdio.h>

int main(void) {
    int n = 0;
    long long f[2000000] = {1, 1};
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        for (int p = 1; p <= 6; p++) {
            if (i - p >= 0) {
                f[i] += f[i - p];
                f[i] %= (1000000007);
            }
        }
    }
    printf("%lld", f[n]);
}