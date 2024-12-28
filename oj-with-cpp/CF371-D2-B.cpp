#include <bits/stdc++.h>

int main(void) {
    int num[2];
    std::cin >> num[0] >> num[1];
    int two[2] = {0}, three[2] = {0}, five[2] = {0};
    for (int i = 0; i < 2; i++) {
        while (num[i] % 2 == 0) {
            num[i] /= 2;
            two[i] += 1;
        }
        while (num[i] % 3 == 0) {
            num[i] /= 3;
            three[i] += 1;
        }
        while (num[i] % 5 == 0) {
            num[i] /= 5;
            five[i] += 1;
        }
    }
    if (num[0] != num[1]) {
        std::cout << -1;
    } else {
        std::cout << abs(two[0] - two[1]) + abs(five[0] - five[1]) + abs(three[0] - three[1]);
    }
    return 0;
}