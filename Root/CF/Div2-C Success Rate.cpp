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



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;

        if (p == 0) {
            if (x == 0) cout << 0 << endl;
            else cout << -1 << endl;
        } else if (p == q) {
            if (x == y) cout << 0 << endl;
            else cout << -1 << endl;
        } else {
            ll nx = (x / p) * p;
            if (nx < x) nx += p;

            ll lo = 0, hi = 1E9 + 10, ans;

            while (lo <= hi) {
                ll mid = (lo + hi) / 2;
                ll ny = ((nx + mid * p) / p) * q;
                if (ny >= y && (ny - y) >= ((nx + mid * p) - x)) {
                    ans = ny - y;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}





