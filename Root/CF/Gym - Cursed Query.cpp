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

ll a[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (i) {
            a[i] = a[i-1] + x;
        } else {
            a[i] = x - 1;
        }
        tot += x;
    }

    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;
        x %= tot;

        int lo = 0;
        int hi = n - 1;
        int ans;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (a[mid] >= x) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans + 1 << '\n';
    }


    return 0;
}






