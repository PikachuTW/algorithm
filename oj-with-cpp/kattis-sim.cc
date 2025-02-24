// https://open.kattis.com/problems/sim

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string input;
        getline(cin, input);
        deque<string> d = {""};
        int pos = 0;
        for (char i : input) {
            if (i == '<') {
                bool deleted = false;
                while (!deleted) {
                    if (d[pos].size() > 0) {
                        d[pos].pop_back();
                        deleted = true;
                    } else if (pos > 0) {
                        if (pos == d.size() - 1) {
                            d.pop_back();
                        }
                        pos -= 1;
                    } else {
                        break;
                    }
                }
            } else if (i == '[') {
                d.push_front("");
                pos = 0;
            } else if (i == ']') {
                pos = d.size() - 1;
            } else {
                d[pos].push_back(i);
            }
        }
        for (string s : d) {
            cout << s;
        }
        cout << "\n";
    }
}