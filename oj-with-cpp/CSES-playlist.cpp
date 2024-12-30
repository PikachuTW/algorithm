#include <bits/stdc++.h>
using namespace std;

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    map<int, int> pos;
    int left = 0;
    int maxSeq = 0;
    for (int right = 0; right < n; right++) {
        if (pos.count(list[right]) && pos[list[right]] >= left) {
            left = pos[list[right]] + 1;
        }
        pos[list[right]] = right;
        maxSeq = max(maxSeq, right - left + 1);
    }
    cout << maxSeq;
    return 0;
}