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
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, k, x;
    while (cin >> n >> k >> x) {
        vector <ll> v(n+2, 0), a(n+2, 0), b(n+2, 0);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++) {
            a[i] = v[i] | a[i-1];
        }
        for (int i = n; i >= 1; i--) {
            b[i] = v[i] | b[i+1];
        }

        ll xx = 1;
        while (k--) {
            xx *= (ll)x;
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, a[i-1]|(v[i]*xx)|b[i+1]);
        }

        cout << ans << endl;
    }


    return 0;
}


