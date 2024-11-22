#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 2 || n == 3) {
        printf("NO SOLUTION");
    } else {
        for (int i = n - 1; i >= 1; i -= 2) {
            printf("%d ", i);
        }
        for (int i = n; i >= 1; i -= 2) {
            printf("%d ", i);
        }
    }
    return 0;
}