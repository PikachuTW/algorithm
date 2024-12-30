#include <bits/stdc++.h>
using namespace std;

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n;
    cin >> n;
    unordered_map<string, int> table;
    vector<string> ss;
    vector<int> points;
    string s;
    int point;
    while (n--) {
        cin >> s >> point;
        ss.emplace_back(s);
        points.emplace_back(point);
        table[s] += point;
    }
    int maxPoint = INT_MIN;
    for (const auto& [key, value] : table) {
        maxPoint = max(maxPoint, value);
    }
    unordered_map<string, int> secondTable;
    for (int i = 0; i < ss.size(); i++) {
        secondTable[ss[i]] += points[i];
        if (secondTable[ss[i]] >= maxPoint && table[ss[i]] == maxPoint) {
            cout << ss[i];
            break;
        }
    }
    return 0;
}