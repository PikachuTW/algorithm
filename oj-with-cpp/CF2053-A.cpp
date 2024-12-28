#include <bits/stdc++.h>

int main(void) {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        int list[200] = {0};
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> list[i];
        }
        bool work = false;
        for (int i = 0; i < n - 1; i++) {
            if (std::min(list[i], list[i + 1]) * 2 > std::max(list[i], list[i + 1])) {
                work = true;
                break;
            }
        }
        if (work) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}