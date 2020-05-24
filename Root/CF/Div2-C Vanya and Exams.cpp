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

pii a[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int n;
    ll r, avg;

    while(cin >> n >> r >> avg) {
        ll need = n * avg, ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i].X >> a[i].Y;
            swap(a[i].X, a[i].Y);
            need -= a[i].Y;
        }

        sort(a, a+n);

        for (int i = 0; i < n; i++) {
            if (need <= 0) break;
            ll pos = r - a[i].Y;
            if (need >= pos) {
                ans += a[i].X * pos;
                need -= pos;
            } else {
                ans += a[i].X * need;
                need = 0;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}






