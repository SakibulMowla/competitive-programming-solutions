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

#define SZ  100010

struct data {
    int a, b, d;
};

data x[SZ];

bool comp (data p, data q) {
    return p.d > q.d;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int n, xx, yy;
    cin >> n >> xx >> yy;

    for (int i = 0; i < n; i++) {
        cin >> x[i].a;
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i].b;
        x[i].d = abs(x[i].a - x[i].b);
    }

    sort(x, x + n, comp);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!xx) {
            ans += x[i].b;
            yy--;
        } else if (!yy) {
            ans += x[i].a;
            xx--;
        } else if (x[i].a > x[i].b) {
            ans += x[i].a;
            xx--;
        } else {
            ans += x[i].b;
            yy--;
        }
    }

    cout << ans << '\n';

    return 0;
}




