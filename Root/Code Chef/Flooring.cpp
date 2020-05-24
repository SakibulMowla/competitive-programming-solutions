#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

ll mod = 1LL;

ll kk[6];

ll npower4(ll k)
{
    int i;

    kk[1] = k % mod;
    for(i=2; i<=5; i++)
        kk[i] = ( kk[i-1] * k ) % mod;

    ll ans;

    ans = ( kk[5] * 6LL ) % mod;
    ans = ( ans + (kk[4] * 15LL) % mod ) % mod;
    ans = ( ans + (kk[3] * 10LL) % mod ) % mod;
    ans = ( ( ( ans - kk[1] ) % mod ) + mod ) % mod;
    ans = ans / 30LL;

    return ans;
}

int main() {
    ll t, n, m, root, prev, curr, i, j;
    ll ans, tmp;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        mod = m * 30LL;

        root = sqrt(n);
        ans = 0LL;

        for(i = 1; i <= root; i++) {
            tmp = (((((i * i) % m) * i) % m) * i) % m;
            tmp = (tmp * (n/i)) % m;
            ans = (ans + tmp) % m;
            if(i * (i+1) <= n) {
                tmp = ( ( ( npower4(n/i) - npower4(n/(i+1LL)) ) % m ) + m ) % m;
                tmp = (tmp * i) % m;
                ans = (ans + tmp) % m;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}


