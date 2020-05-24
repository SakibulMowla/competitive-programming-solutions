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
const ll mod = 1E9;


#define SZ 100010

ll cntOccrnc (ll a, ll b, ll p) {
    return (b/p) - ((a-1LL)/p);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    ll n, p;
    while (cin >> n >> p) {
        vector <pll> a(n);
        vector <ll> r(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].X >> a[i].Y;
            r[i] = a[i].Y - a[i].X + 1;
        }
        a.pb(a[0]);
        r.pb(a[0].Y - a[0].X + 1);

        double ans = 0;
        for (int i = 0; i < n; i++) {
            ll c1 = cntOccrnc(a[i].X, a[i].Y, p);
            ll c2 = cntOccrnc(a[i+1].X, a[i+1].Y, p);
            ans += (((double)c1 * (double)r[i+1] + (double)c2 * (double)r[i] - (double)c1 * (double)c2) * 2000.0) /
                                ((double)r[i] * (double)r[i+1]);
        }

        cout << fixed << setprecision(12) << ans << endl;
    }


    return 0;
}





