#include <bits/stdc++.h>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    while (n >= 0) {
        if (n % 11 == 0) {
            cout << "YES\n";
            return;
        }
        n -= 111;
    }
    cout << "NO\n";
}

int main(void) {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}