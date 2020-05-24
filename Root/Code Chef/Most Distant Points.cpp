#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  500010

multiset <ll> ms;
pii a[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
//    cin.tie(0);

    int q, cnt = 0;
    ll ans = 0LL;

    cin >> q;

    for (int cs = 0; cs < q; cs++) {
        char c;
        cin >> c;
        if (c == '+') {
            ll x, y;
            cin >> x >> y;
            x ^= ans;
            y ^= ans;
            a[++cnt] = MP(x, y);
            ms.insert(x+y);
            ms.insert(x-y);
            ms.insert(-x+y);
            ms.insert(-x-y);
        } else if (c == '-') {
            ll n;
            cin >> n;
            n ^= ans;
            ll x = a[n].X;
            ll y = a[n].Y;
            ms.erase(ms.find(x+y));
            ms.erase(ms.find(x-y));
            ms.erase(ms.find(-x+y));
            ms.erase(ms.find(-x-y));
        } else {
            ll x, y;
            cin >> x >> y;
            x ^= ans;
            y ^= ans;
            ll tmp = (x+y) - (*ms.begin());
            tmp = max(tmp, (x-y) - (*ms.begin()));
            tmp = max(tmp, (-x+y) - (*ms.begin()));
            tmp = max(tmp, (-x-y) - (*ms.begin()));
            ans = tmp;
            cout << ans << '\n';
        }
    }

    return 0;
}





