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

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        ll k;
        cin >> n >> k;

        ll now = 0;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;

            if (a <= now) {
                now -= a;
            } else {
                ll need = a - now;
                ll bread = (need / k) + (bool)(need % k);
                ans += bread;
                now += bread * k - a;
            }

            if (now) {
                now--;
            }
        }

        cout << ans << endl;
    }


    return 0;
}






