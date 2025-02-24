// https://open.kattis.com/problems/backspace

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    deque<char> cs;
    for (char c : s) {
        if (c != '<') {
            cs.push_back(c);
        } else if (cs.size() >= 1) {
            cs.pop_back();
        }
    }
    for (char c : cs) {
        cout << c;
    }
    return 0;
}