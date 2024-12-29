#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int ticketNum, customerNum;
    cin >> ticketNum >> customerNum;
    multiset<int> tickets;
    while (ticketNum--) {
        int price;
        cin >> price;
        tickets.insert(price);
    }
    while (customerNum--) {
        int will;
        cin >> will;
        auto pos = tickets.upper_bound(will);
        if (pos == tickets.begin()) {
            cout << "-1\n";
        } else {
            cout << *--pos << "\n";
            tickets.erase(pos);
        }
    }
}