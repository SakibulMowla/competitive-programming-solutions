#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1E9+7;

#define SZ  200010

ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

ll f[SZ];
ll invf[SZ];

inline ll ways (int n, int m) {
    return (((f[n+m-2] * invf[n-1]) % mod) * invf[m-1]) % mod;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    f[0] = 1;
    invf[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        f[i] = ((ll)i * f[i-1]) % mod;
        invf[i] = BigMod(f[i], mod-2, mod);
    }

    pii a[1010];
    ll path[1010];

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m, k;
        cin >> n >> m >> k;

        for (int i = 0; i < k; i++) {
            cin >> a[i].X >> a[i].Y;
        }

        sort(a, a+k);

        ll ans = ways(n, m);

        for (int i = 0; i < k; i++) {
            ll x = ways(a[i].X, a[i].Y);
            ll y = ways(n-a[i].X+1, m-a[i].Y+1);

            for (int j = 0; j < i; j++) {
                if (a[j].X <= a[i].X && a[j].Y <= a[i].Y) {
                    x = x - ((path[j] * ways(a[i].X-a[j].X+1, a[i].Y-a[j].Y+1)) % mod);
                    if (x < 0) {
                        x += mod;
                    }
                }
            }

            path[i] = x;
            ans = ans - ((x * y) % mod);
            if (ans < 0) {
                ans += mod;
            }
        }

        cout << ans << '\n';
    }


    return 0;
}




