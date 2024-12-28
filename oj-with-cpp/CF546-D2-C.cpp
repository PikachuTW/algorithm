#include <bits/stdc++.h>
using namespace std;

int main(void) {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n, a, b;
    cin >> n;
    queue<int> aList, bList;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int num;
        cin >> num;
        aList.emplace(num);
    }
    cin >> b;
    for (int i = 0; i < b; i++) {
        int num;
        cin >> num;
        bList.emplace(num);
    }
    for (int i = 0; i < 100000; i++) {
        int aNum = aList.front();
        int bNum = bList.front();
        aList.pop(), bList.pop();
        if (aNum > bNum) {
            aList.emplace(bNum);
            aList.emplace(aNum);
        } else {
            bList.emplace(aNum);
            bList.emplace(bNum);
        }
        if (aList.size() == 0) {
            cout << i + 1 << " " << 2;
            return 0;
        } else if (bList.size() == 0) {
            cout << i + 1 << " " << 1;
            return 0;
        }
    }
    cout << -1;
}
