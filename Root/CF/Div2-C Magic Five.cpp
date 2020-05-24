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
const ll mod = 1000000007;

#define SZ 100010

ll Bigmod (ll p, ll b = 2) {
    ll r = 1;
    while (p) {
        if (p & 1) r = (r * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return r;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    string s;
    int k;

    while (cin >> s >> k) {
        ll ans = 0;
        int n = sz(s);
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == '0' || s[i] == '5') {
                ll tmp = Bigmod(i);
                tmp = (tmp * ( (Bigmod((ll)n * (ll)k) - 1LL + mod) % mod )) % mod;
                ll tmp1 = (Bigmod(n) - 1 + mod) % mod;
                tmp = (tmp * Bigmod(mod-2, tmp1)) % mod;
                ans = (ans + tmp) % mod;
            }
        }
        cout << ans << '\n';
    }


    return 0;
}







