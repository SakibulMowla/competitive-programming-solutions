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
const ll mod = 1E9;

#define SZ 200010

int calc (pll &a, pll &b, pll &c) {
    ll v = (c.X - a.X) * (a.Y - b.Y) - (a.X - b.X) * (c.Y - a.Y);
    if (v < 0) v = -1;
    else if (v > 0) v = 1;
    return v;
}

int main() {
//    #if defined JESI
        freopen("kingdom.in", "r", stdin);
        freopen("kingdom.out", "w", stdout);
//    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n) {
        vector <pll> points(n + n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].X >> points[i].Y;
            points[i + n] = points[i];
        }

        pll a, b;
        cin >> a.X >> a.Y;
        cin >> b.X >> b.Y;

        ll ans = 0;

        for (int i = 0, j = 1, k = 1; i < n; i++) {
            if (i >= j) j = i + 1;
            if (i >= k) k = i + 1;
            while (j < i + n && calc(points[i], points[j], a) >= 0) j++;
            while (k < i + n && calc(points[i], points[k], b) > 0) k++;
            if (k > j) ans += (ll)(k - j);
        }

        cout << ans << endl;
    }


    return 0;
}







