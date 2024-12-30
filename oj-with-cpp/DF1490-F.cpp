#include <bits/stdc++.h>
using namespace std;

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> counts;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            counts[k] += 1;
        }
        map<int, int> countGroup;
        for (auto &[key, element] : counts) {
            countGroup[element] += 1;
        }
        int res = n;
        int sum = n;
        int remain = counts.size();
        for (auto &[key, element] : countGroup) {
            res = min(res, sum - remain * key);
            remain -= element;
        }
        cout << res << "\n";
    }
    return 0;
}