#include "bits/stdc++.h"

using namespace std;

using ll = long long int;

#define SZ 510

const ll mod = 1E9 + 7;

inline ll R (ll n) {
    return n % mod;
}

ll dp[SZ][SZ];
int b[SZ];

ll solve (int l, int r) {
    if (l == r) {
        dp[l][r] = 1;
    } else if (dp[l][r] == -1) {
        ll ans = 0;
        for (int i = l + 1; i <= r; i++) {
            if (i == r || b[l+1] < b[i+1]){
                ans = R(ans + R(solve(l+1, i) * solve(i, r)));
            }
        }
        dp[l][r] = ans;
    }
    return dp[l][r];
}

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    memset (dp, -1, sizeof dp);

    cout << solve (1, n) << '\n';

    return 0;
}
