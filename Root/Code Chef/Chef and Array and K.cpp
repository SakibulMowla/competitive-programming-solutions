#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9 + 7;


#define SZ 100010

ll BigMod (ll B, ll P, ll M) {
    ll R = 1 % M;
    while(P > 0) {
        if(P % 2 == 1) {
            R = (R * B) % M;
        }
        P /= 2;
        B = (B * B) % M;
    }
    return R;
}

ll f[SZ];

ll nCr (int n, int r) {
    if (r > n) return 0;
    ll ans = f[n];
    ans = (ans * BigMod(f[r], mod - 2, mod)) % mod;
    ans = (ans * BigMod(f[n - r], mod - 2, mod)) % mod;
    return ans;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    f[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        f[i] = ((ll)i * f[i-1]) % mod;
    }

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        scanf("%d %d", &n, &k);

        int zeros = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            zeros += !x;
        }

        ll ans = 0;

        if (zeros) {
            for (int i = 0; i <= min(n - zeros, k); i++) {
                ans = ans + nCr(n - zeros, i);
                if (ans >= mod) {
                    ans -= mod;
                }
            }
        } else {
            if (k > n) {
                k = n - ((k - n) & 1);
            }
            for (int i = k; i >= 0; i -= 2) {
                ans = ans + nCr(n, i);
                if (ans >= mod) {
                    ans -= mod;
                }
            }
        }

        printf("%lld\n", ans);
    }


    return 0;
}




