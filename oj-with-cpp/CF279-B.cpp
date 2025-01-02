#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    ll n, t;
    cin >> n >> t;
    vector<ll> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    int maxLen = 0;
    ll sum = 0;
    int l = 0, r = 0;
    while (r < n) {
        if (sum + costs[r] <= t) {
            sum += costs[r];
            r += 1;
            maxLen = max(maxLen, r - l);
        } else {
            sum -= costs[l];
            l += 1;
        }
    }
    cout << maxLen;
    return 0;
}