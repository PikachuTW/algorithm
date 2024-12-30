#include <bits/stdc++.h>
using namespace std;

#define SIZE 100007

long long nums[SIZE] = {0};
long long dp[SIZE] = {0};

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n, num;
    cin >> n;
    while (n--) {
        cin >> num;
        nums[num] += 1;
    }
    dp[0] = 0;
    dp[1] = nums[1];
    for (int i = 2; i < SIZE; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i] * i);
    }
    cout << dp[SIZE - 1];
}