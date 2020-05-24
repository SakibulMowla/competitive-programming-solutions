#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = (1E9)+7;

#define SZ 200010

ll f[SZ];
ll inv[SZ];
ll store[2020];

ll BigMod (ll B, ll P, ll M) {
    ll R = 1 % M;
    while(P > 0) {
        if (P % 2 == 1) {
            R = (R * B) % M;
        }
        P /= 2;
        B = (B * B) % M;
    }
    return R;
}

ll get (int n, int m) {
    ll ans = f[n + m];
    ans = (ans * inv[n]) % mod;
    ans = (ans * inv[m]) % mod;
    return ans;
}

int main() {
#if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);

    f[0] = 1;
    inv[0] = BigMod(f[0], mod - 2, mod);
    for (int i = 1; i <= 200000; i++) {
        f[i] = ((ll)i * f[i-1]) % mod;
        inv[i] = BigMod(f[i], mod - 2, mod);
    }

    int r, c, n;
    while (cin >> r >> c >> n) {
        vector <pii> v(n, {0, 0});
        for (int i = 0; i < n; i++) {
            cin >> v[i].X >> v[i].Y;
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) {
            store[i] = get(v[i].X - 1, v[i].Y - 1);
            for (int j = 0; j < i; j++) {
                if (v[j].X > v[i].X || v[j].Y > v[i].Y) continue;
                store[i] = (store[i] - ((store[j] * get(v[i].X - v[j].X, v[i].Y - v[j].Y)) % mod) + mod) % mod;
            }
        }

        ll ans = get(r - 1, c - 1);
        for (int i = 0; i < n; i++) {
            ans = (ans - ((store[i] * get(r - v[i].X, c - v[i].Y)) % mod) + mod) % mod;
        }

        cout << ans << endl;
    }

    return 0;
}







