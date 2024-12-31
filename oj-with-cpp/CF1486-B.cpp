#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long ansX = 0;
    if (x.size() % 2 == 0) {
        ansX = x[x.size() / 2] - x[x.size() / 2 - 1] + 1;
    } else {
        ansX = 1;
    }
    long long ansY = 0;
    if (y.size() % 2 == 0) {
        ansY = y[y.size() / 2] - y[y.size() / 2 - 1] + 1;
    } else {
        ansY = 1;
    }
    cout << ansX * ansY << "\n";
}

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}