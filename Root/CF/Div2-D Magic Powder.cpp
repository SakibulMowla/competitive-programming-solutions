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

//    ios::sync_with_stdio(false);

    ll n, k;
    scanf("%I64d %I64d", &n, &k);

    vector <ll> a(n), b(n);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &b[i]);
    }

    ll lo = 0, hi = 2E9, ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2LL;
        ll tmpk = k;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            ll need = mid * a[i] - b[i];
            if (need > 0) {
                if (tmpk >= need) {
                    tmpk -= need;
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}





