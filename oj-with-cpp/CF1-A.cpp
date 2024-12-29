#include <bits/stdc++.h>

int main(void) {
    double n, m, a;
    std::cin >> n >> m >> a;
    std::cout << (long long)ceil(n / a) * (long long)ceil(m / a);
    return 0;
}