#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1E9+7;

#define SZ 100010

ll f[SZ];
ll x[SZ];
ll p[SZ];

inline ll R (ll n) {
    n = n % mod;
    if (n < 0) n += mod;
    return n;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    ll a, b;
    cin >> n >> q >> f[1] >> f[2] >> a >> b;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for (int i = 3; i <= n; i++) {
        f[i] = R(a * f[i-2] + b * f[i-1]);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        p[l] = R(p[l] + f[1]);
        p[l+1] = R(p[l+1] + f[2] - b * f[1]);
        p[r+1] = R(p[r+1] - f[r-l+2]);
        p[r+2] = R(p[r+2] - R(a * f[r-l+1]));
    }

    for (int i = 2; i <= n; i++) {
        p[i] = R(p[i] + a * p[i-2] + b * p[i-1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << R(p[i] + x[i]) << ' ';
    }
    cout << '\n';

    return 0;
}






