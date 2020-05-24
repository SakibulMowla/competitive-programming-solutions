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

#define SZ 100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0, lim = 1 << n;
    for (int mask = 0; mask < lim; mask++) {
        if (__builtin_popcount(mask) > 1) {
            int tot = 0;
            int mn = 1E7;
            int mx = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1<<i)) {
                    tot += a[i];
                    mn = min(mn, a[i]);
                    mx = max(mx, a[i]);
                }
            }
            if (tot >= l && tot <= r && mx - mn >= x) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}







