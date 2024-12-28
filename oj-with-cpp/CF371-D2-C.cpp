#include <bits/stdc++.h>

int main(void) {
    std::string s;
    int n[3];
    int p[3];
    long long money;
    std::cin >> s >>
        n[0] >> n[1] >> n[2] >>
        p[0] >> p[1] >> p[2] >>
        money;
    int recipe[3] = {0};
    for (char c : s) {
        if (c == 'B') {
            recipe[0] += 1;
        } else if (c == 'S') {
            recipe[1] += 1;
        } else {
            recipe[2] += 1;
        }
    }
    long long left = 0, right = 1.5e12;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long money_need = std::max(0LL, (recipe[0] * mid) - n[0]) * p[0] +
                               std::max(0LL, (recipe[1] * mid) - n[1]) * p[1] +
                               std::max(0LL, (recipe[2] * mid) - n[2]) * p[2];
        if (money_need <= money) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    std::cout << left - 1;
    return 0;
}