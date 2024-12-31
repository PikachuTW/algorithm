#include <bits/stdc++.h>
using namespace std;

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long prefix_sum = 0;
    set<long long> exist;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        prefix_sum += arr[i - 1];
        if (exist.count(prefix_sum)) {
            ans += 1;
            prefix_sum = arr[i - 1];
            exist.clear();
            exist.emplace(0);
        }
        exist.emplace(prefix_sum);
    }
    cout << ans;
    return 0;
}