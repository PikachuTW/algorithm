#include <stdio.h>

int pos[250000];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        pos[k] = i;
    }
    int ans = 1;
    for (int i = 1; i <= n - 1; i++) {
        if (pos[i] > pos[i + 1]) ans += 1;
    }
    printf("%d", ans);
    return 0;
}