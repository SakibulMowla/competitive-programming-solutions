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


#define SZ 1010

int a[SZ][SZ];

ll cnt1 (int x, int y) {
    ll cnt = 0;
    while (x <= 1000 && y <= 1000) {
        if (a[x][y]) cnt++;
        x++;
        y++;
    }
    return cnt;
}

ll cnt2 (int x, int y) {
    ll cnt = 0;
    while (x >= 1 && y <= 1000) {
        if (a[x][y]) cnt++;
        x--;
        y++;
    }
    return cnt;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        mem(a, 0);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            a[x][y]++;
        }

        ll ans = 0;

        for (int i = 1; i <= 1000; i++) {
            ll x = cnt1(1, i);
            ans += (x * (x - 1LL) / 2LL);
        }
        for (int i = 2; i <= 1000; i++) {
            ll x = cnt1(i, 1);
            ans += (x * (x - 1LL) / 2LL);
        }

        for (int i = 1; i <= 1000; i++) {
            ll x = cnt2(1000, i);
            ans += (x * (x - 1LL) / 2LL);
        }
        for (int i = 1; i <= 999; i++) {
            ll x = cnt2(i, 1);
            ans += (x * (x - 1LL) / 2LL);
        }

        cout << ans << endl;
    }

    return 0;
}





