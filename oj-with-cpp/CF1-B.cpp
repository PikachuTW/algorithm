#include <bits/stdc++.h>

int main(void) {
    int n;
    std::cin >> n;
    while (n--) {
        std::string s;
        std::cin >> s;
        bool isRc = false;
        if (s[0] == 'R') {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] == 'C' && i != 1) {
                    isRc = true;
                    break;
                } else if (!isdigit(s[i])) {
                    break;
                }
            }
        }
        if (isRc) {
            int R, C;
            sscanf(s.c_str(), "R%dC%d", &R, &C);
            std::string xStr = "";
            while (C > 0) {
                C--;
                xStr += (C % 26 + 'A');
                C /= 26;
            }
            for (int i = xStr.size() - 1; i >= 0; i--) {
                std::cout << xStr[i];
            }
            std::cout << R << "\n";
        } else {
            int C = 0, R = 0;
            for (char c : s) {
                if (isdigit(c)) {
                    R *= 10;
                    R += (c - '0');
                } else {
                    C *= 26;
                    C += (c - 'A' + 1);
                }
            }
            std::cout << "R" << R << "C" << C << "\n";
        }
    }
}