#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;
using ll = unsigned long long;

int main() {
    ios::sync_with_stdio(false);

    vector<ll> layer(64, 1);
    for (int i = 1; i < 64; i++) {
        layer[i] = 2 * layer[i - 1] + 1;
    }

    int tests;
    cin >> tests;

    while (tests--) {
        ll n;
        cin >> n;

        ll ans = 0;

        for (int i = 0; i < 64; i++) {
            if (n & (1LL << i)) {
                ans += layer[i];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

/*
               1
              2 1
            3 1 2 1
        4 1 2 1 3 1 2 1
5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1
*/
