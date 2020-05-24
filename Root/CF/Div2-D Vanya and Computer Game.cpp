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
const ll mod = 1LL;

#define SZ 100010

ll bs (ll &val, ll &x, ll &y, ll &l) {
    ll lo, hi, mid, tmp, ans;

    lo = 0;
    hi = 1E16;

    while (lo <= hi) {
        mid = (lo + hi) >> 1LL;
        tmp = (mid / x) + (mid / y) - (mid / l);
        if (tmp >= val) {
            ans = mid;
            hi = mid - 1LL;
        } else lo = mid + 1LL;
    }

    return ans;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int n;
    ll x, y;

    while(cin >> n >> x >> y) {
        ll l = x / __gcd(x, y) * y;

        x = l / x;
        y = l / y;

        l = x / __gcd(x, y) * y;

//        cout << ">> x = " << x << " l = " << l << " y = " << y << '\n';

        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;

            ll that = bs(a, x, y, l);

//            cout << ">> a = " << a << " that = " << that << '\n';

            bool f1 = (that % x == 0);
            bool f2 = (that % y == 0);

            if (f1 && f2) cout << "Both\n";
            else if (f1) cout << "Vanya\n";
            else cout << "Vova\n";
        }
    }

    return 0;
}






