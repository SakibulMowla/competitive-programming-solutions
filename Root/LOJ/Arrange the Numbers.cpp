#include "bits/stdc++.h"

using namespace std;

#define SZ 1010

typedef long long ll;

const ll mod = 1000000007LL;

ll fact[SZ];
ll nCr[SZ][SZ];

int main () {
    fact[0] = 1LL;
    for (int i = 1; i <= 1000; i++) {
        fact[i] = ((ll)i * fact[i-1]) % mod;
    }
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) nCr[i][j] = 1LL;
            else if (j == 1) nCr[i][j] = i;
            else nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % mod;
        }
    }

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        ll ans = nCr[m][k];

        n -= k;
        m -= k;

        ll tmp = 0LL;
        for (int i = 0; i <= m; i++) {
            if (i & 1) {
                tmp = (tmp - ((nCr[m][i] * fact[n-i]) % mod)) % mod;
            } else {
                tmp = (tmp + ((nCr[m][i] * fact[n-i]) % mod)) % mod;
            }
        }
        tmp = (tmp + mod) % mod;
        ans = (ans * tmp) % mod;

        printf("Case %d: %lld\n", cs + 1, ans);
    }


    return 0;
}
