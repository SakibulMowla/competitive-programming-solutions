#include "bits/stdc++.h"

using namespace std;
using ll = long long;

#define SZ 100010

const ll mod = 1000000007;

ll bp[27][SZ];

int main() {
    ios::sync_with_stdio(false);

    for (int i = 1; i <= 26; i++) {
        bp[i][0] = 1;
        for (int j = 1; j <= 100000; j++) {
            bp[i][j] = ((ll)i * bp[i][j-1]) % mod;
        }
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        ll ans = (bp[m][n] - bp[m][(n / 2) + (n % 2)] + mod) % mod;
        cout << "Case " << cs + 1 << ": " << ans << endl;
    }

    return 0;
}
