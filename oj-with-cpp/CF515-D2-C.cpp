#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int digits[10] = {0};
    for (char c : s) {
        digits[c - '0'] += 1;
    }
    /*
    2 2
    3 3
    4 322
    5 5
    6 53
    7 7
    8 7222
    9 7332
    */
    digits[2] += 2 * digits[4] + 3 * digits[8] + digits[9];
    digits[3] += digits[4] + digits[6] + 2 * digits[9];
    digits[5] += digits[6];
    digits[7] += digits[8] + digits[9];
    for (int i = 0; i < digits[7]; i++) {
        printf("7");
    }
    for (int i = 0; i < digits[5]; i++) {
        printf("5");
    }
    for (int i = 0; i < digits[3]; i++) {
        printf("3");
    }
    for (int i = 0; i < digits[2]; i++) {
        printf("2");
    }
    return 0;
}