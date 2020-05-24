#include<bits/stdc++.h>

using namespace std;

int main () {
    double r;
    while (cin >> r) {
        int n = ceil((sqrt(8.0 * r + 1.0) - 1.0) / 2.0);
        int lft = r - (n * (n - 1) / 2);
        int x = n - lft + 1;
        int y = lft;
        if (n & 1) swap(x, y);
        cout << x << ' ' << y << endl;
    }
    return 0;
}
