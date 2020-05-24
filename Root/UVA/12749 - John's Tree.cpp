#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

const ll mod = 1000000007LL;

#define SZ  110


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test = 0, t;
    scanf("%d", &t);

    while(t--) {
        ll d, v;
        scanf("%lld %lld", &d, &v);

        ll ans;
        if(v == 1) {
            ans = (d <= 1) ? (d+1LL)%mod : -1LL;
        } else if(v == 2) {
            ans = ( (2LL * d) + 1LL ) % mod;
        } else {
            ans = (BigMod(v-1LL, d, mod) - 1LL + mod) % mod;
            ans = (ans * BigMod(v-2LL, mod-2, mod)) % mod;
            ans = (v * ans) % mod;
            ans = (ans + 1LL) % mod;
        }

        printf("Case %d: %lld\n", ++test, ans);
    }

    return 0;
}









