#include <stdio.h>
#define SIZE 250000

int pos[SIZE];
int nums[SIZE];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        pos[k] = i;
        nums[i] = k;
    }
    int ans = 1;
    for (int i = 1; i <= n - 1; i++) {
        if (pos[i] > pos[i + 1]) ans += 1;
    }
    return 0;
}