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
const ll mod = 1000000007;


#define SZ 100010

inline ll f (ll n, ll m) {
    return (n * m) % mod;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int p, q, r;
        cin >> p >> q >> r;

        vector <ll> a(p), b(q), c(r);
        for (auto &x: a) cin >> x;
        for (auto &x: b) cin >> x;
        for (auto &x: c) cin >> x;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        ll sum1 = 0, sum2 = 0, ans = 0;
        for (int i = -1, j = 0, k = -1; j < q; j++) {
            while (i + 1 < p && a[i + 1] <= b[j]) i++, sum1 += a[i];
            while (k + 1 < r && c[k + 1] <= b[j]) k++, sum2 += c[k];
            ans = ans + f((sum1 + f(i + 1, b[j])) % mod, (sum2 + f(k + 1, b[j])) % mod);
            if (ans >= mod) ans -= mod;
        }

        cout << ans << endl;
    }

    return 0;
}




