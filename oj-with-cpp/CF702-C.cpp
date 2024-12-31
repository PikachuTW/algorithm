#include <bits/stdc++.h>
using namespace std;

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> cities(n), towers(m);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }
    sort(towers.begin(), towers.end());
    int needR = 0;
    for (int city : cities) {
        int left = 0, right = towers.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (city > towers[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left >= m) {
            needR = max(needR, abs(towers[m - 1] - city));
        } else if (left > 0) {
            needR = max(needR,
                        min(abs(towers[left] - city),
                            abs(towers[left - 1] - city)));
        } else {
            needR = max(needR, abs(towers[left] - city));
        }
    }
    cout << needR;
    return 0;
}