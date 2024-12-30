#include <bits/stdc++.h>
using namespace std;

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n, d;
    cin >> n >> d;
    vector<pair<long long, long long>> friends(n);
    for (int i = 0; i < n; i++) {
        cin >> friends[i].first >> friends[i].second;
    }
    sort(friends.begin(), friends.end());
    vector<long long> prefix_sum(n);
    prefix_sum[0] = friends[0].second;
    for (int i = 1; i < n; i++) {
        prefix_sum[i] += prefix_sum[i - 1] + friends[i].second;
    }
    int lastMoney = -1;
    long long maxSum = 0;
    for (int i = 0; i < n; i++) {
        if (friends[i].first != lastMoney) {
            lastMoney = friends[i].first;
            int left = i, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (friends[mid].first >= friends[i].first + d) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (i == 0) {
                maxSum = max(maxSum, prefix_sum[left - 1]);
            } else {
                maxSum = max(maxSum, prefix_sum[left - 1] - prefix_sum[i - 1]);
            }
        }
    }
    cout << maxSum;
    return 0;
}