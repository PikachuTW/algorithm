#include <bits/stdc++.h>
using namespace std;

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int m, n;
    cin >> m >> n;
    string s, t;
    cin >> s >> t;
    vector<int> left(n, 0);
    vector<int> right(n, m - 1);

    int pos = 0;
    for (int i = 0; i < n; i++) {
        while (pos < m && s[pos] != t[i]) pos += 1;
        left[i] = pos;
        pos += 1;
    }
    pos = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (pos >= 0 && s[pos] != t[i]) pos -= 1;
        right[i] = pos;
        pos -= 1;
    }
    int maxWidth = 0;
    for (int i = 1; i < n; i++) {
        maxWidth = max(maxWidth, right[i] - left[i - 1]);
    }
    cout << maxWidth;
    return 0;
}