#include <bits/stdc++.h>
using namespace std;

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n, q;
    cin >> n >> q;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<long long> counts(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        counts[l - 1] += 1;
        counts[r] -= 1;
    }
    for (int i = 1; i < n; i++) {
        counts[i] += counts[i - 1];
    }
    counts.pop_back();
    sort(counts.begin(), counts.end());
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i] * counts[i];
    }
    cout << sum;
    return 0;
}