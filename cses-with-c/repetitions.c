#include <stdio.h>

int main(void) {
    char c;
    char last = '\0';
    int ans = 0;
    int maxAns = 0;
    while (scanf("%c", &c) != EOF) {
        if (last == '\0') last = c;
        if (c == last) {
            ans += 1;
        } else {
            maxAns = ((maxAns > ans) ? maxAns : ans);
            ans = 1;
            last = c;
        }
    }
    printf("%d", maxAns);
    return 0;
}