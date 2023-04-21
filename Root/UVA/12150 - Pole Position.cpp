#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        bool isPossible = true;
        vector<int> startingOrder(n, 0);
        int car, change;
        for (int i = 0; i < n; i++) {
            cin >> car >> change;
            int prevPosition = i + change;
            if (prevPosition >= 0 && prevPosition < n && startingOrder[prevPosition] == 0) {
                startingOrder[prevPosition] = car;
            } else {
                isPossible = false;
            }
        }
        if (isPossible) {
            for (int i = 0; i < n; i++) {
                cout << (i ? " " : "")<< startingOrder[i];
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
