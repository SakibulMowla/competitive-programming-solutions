#include <stdio.h>
#include <vector>
#include <iostream>

using namespace  std;
using ll = long long;

int solve(ll n, int flip) {
    if (0 == (n & (n - 1)))
        return flip;
    for (int i = 62; ; i--) {
        if ((n >> i) & 1) {
            return solve((1LL << i) - (n & ~(1LL << i)), flip ^ 1);
        }
    }
}

int main() {
//    #if defined JESI
        freopen("B-large.in", "r", stdin);
        freopen("2.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll n;
        cin >> n;
        cout << "Case #" << cs + 1 << ": " << solve(n, 0) << endl;
    }

    return 0;
}



