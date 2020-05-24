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

ll dist2 (pll a, pll b) {
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

bool comp (pll a, pll b) {
    if (a.X == b.X) return a.Y > b.Y;
    return a.X < b.X;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        pll f1, f2;
        cin >> f1.X >> f1.Y >> f2.X >> f2.Y;
        vector <pll> a(n), dist;
        for (int i = 0; i < n; i++) {
            cin >> a[i].X >> a[i].Y;
            dist.pb({dist2(f1, a[i]), dist2(f2, a[i])});
        }
        sort(dist.begin(), dist.end(), comp);
        vector <ll> mx(n + 1, 1E18);
        mx[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            mx[i] = max(dist[i].Y, mx[i+1]);
        }
        ll ans = mx[0];
        for (int i = 0; i < n; i++) {
            ans = min(ans, dist[i].X + mx[i+1]);
        }
        cout << ans << endl;
    }


    return 0;
}





