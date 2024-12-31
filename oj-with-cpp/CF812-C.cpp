#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> costs(100000);

long long getCost(long long k) {
    vector<long long> factoredCosts(n);
    for (int i = 0; i < n; i++) {
        factoredCosts[i] = costs[i] + (i + 1) * k;
    }
    sort(factoredCosts.begin(), factoredCosts.end());
    long long cost = 0;
    for (int i = 0; i < k; i++) {
        cost += factoredCosts[i];
    }
    return cost;
}

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    cin >> n;
    long long money = 0;
    cin >> money;
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    long long left = 0, right = n;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long cost = getCost(mid + 1);
        if (cost > money) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << " " << getCost(left);
    return 0;
}