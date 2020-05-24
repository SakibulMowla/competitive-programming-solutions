#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1E9 + 7;

#define SZ  500010

ll BigMod(ll B,ll P,ll M) {
    ll R=1%M;
    while(P>0)      {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

ll f[SZ];
ll inv[SZ];

ll nCr (int n, int r) {
    ll ans = f[n];
    ans = (ans * inv[r]) % mod;
    ans = (ans * inv[n - r]) % mod;
    return ans;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    f[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 500000; i++) {
        f[i] = (i * f[i - 1]) % mod;
        inv[i] = BigMod(f[i], mod - 2, mod);
    }

    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        vector <int> a(4, 0);

        for (auto x: s) a[x - 'a']++;

        ll part2 = 0;
        int lim = min(a[2], a[3]);

        for (int i = 0; i <= lim; i++) {
            part2 = part2 + (nCr(a[2], i) * nCr(a[3], i)) % mod;
            if (part2 >= mod) part2 -= mod;
        }

        lim = min(a[0], a[1]);
        ll ans = 0;

        for (int i = 0; i <= lim; i++) {
            ll part1 = (nCr(a[0], i) * nCr(a[1], i)) % mod;
            ans = ans + (part1 * part2) % mod;
            if (ans >= mod) ans -= mod;
        }

        ans--;
        if (ans < 0) ans += mod;

        cout << ans << endl;
    }

    return 0;
}



