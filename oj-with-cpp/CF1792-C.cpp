#include <bits/stdc++.h>
using namespace std;

void solve(void) {
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    int left = (n + 1) / 2;
    int right = (n + 2) / 2;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pos[num] = i;
    }
    while (left >= 1 && right <= n) {
        if (left == right || (pos[left] < pos[left + 1] && pos[right - 1] < pos[right])) {
            left -= 1, right += 1;
        } else {
            break;
        }
    }
    cout << (n - right + left + 1) / 2 << "\n";
}

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#else
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}