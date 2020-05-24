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
const ll mod = 1E8;

#define SZ 110

ll dp[SZ][SZ];
int n, m;

ll solve (int pre, int now, vector <pii> &v) {
    if (v[now].Y == m) return 1;

    ll &ret = dp[pre][now];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = now + 1; i <= n; i++) {
        if (v[i].X > v[now].X && v[i].Y > v[now].Y && v[i].X <= v[now].Y && v[i].X > v[pre].Y) {
            ret = (ret + solve(now, i, v)) % mod;
        }
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    while (cin >> m >> n && (n + m)) {
        vector <pii> v(n + 1);
        v[0] = {0, 0};

        for (int i = 1; i <= n; i++) {
            cin >> v[i].X >> v[i].Y;
        }

        sort(v.begin(), v.end());
        mem(dp, -1);

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i].X == 0) {
                ans = (ans + solve(0, i, v)) % mod;
            }
        }

        cout << ans << endl;
    }


    return 0;
}







