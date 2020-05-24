#include "bits/stdc++.h"

using namespace std;
using ll = long long;

#define SZ 100010

ll a[SZ];
ll dp[SZ][34];

ll gcd (ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        ll n;
        scanf("%lld", &n);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        ll p = 0, q = (n * (n - 1)) / 2;

        memset(dp, 0, sizeof dp);

        for (int i = n - 1; i >= 0; i--) {
            for (ll j = 0; j <= 32; j++) {
                if (a[i] & (1LL << j)) p += (1LL << j) * (ll)(n - i - 1);
                else p += (1LL << j) * dp[i + 1][j];
                dp[i][j] = dp[i + 1][j] + (int)(bool)(a[i] & (1LL << j));
            }
        }

        ll g = gcd(p, q);
        p /= g;
        q /= g;
        printf("%lld/%lld\n", p, q);
    }

    return 0;
}

