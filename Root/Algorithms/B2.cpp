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

#define SZ 52

ll dp[SZ][SZ];

ll solve (int now, int i, int j) {
    ll &ret = dp[i][j];
    if (ret != -1) return ret;
    if (i == j) return ret = 1LL;
    return ret = solve(now+1, i+1, j) + solve(now+1, i, j-1);
}

int a[SZ];

void path (int now, int i, int j, ll lft) {
    if (i == j) {
        a[i] = now;
        return;
    }
    if (lft > dp[i+1][j]) {
        a[j] = now;
        return path(now+1, i, j-1, lft-dp[i+1][j]);
    } else {
        a[i] = now;
        return path(now+1, i+1, j, lft);
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    mem(dp, -1);

    int n;
    ll m;
    while (cin >> n >> m) {
        solve(1, 1, n);
        path(1, 1, n, m);
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/*
1 2 3 4 5  = 35
1 2 3 5 4  = 35
1 2 4 5 3  = 35
1 2 5 4 3  = 35
1 3 4 5 2  = 35
1 3 5 4 2  = 35
1 4 5 3 2  = 35
1 5 4 3 2  = 35
2 3 4 5 1  = 35
2 3 5 4 1  = 35
2 4 5 3 1  = 35
2 5 4 3 1  = 35
3 4 5 2 1  = 35
3 5 4 2 1  = 35
4 5 3 2 1  = 35
5 4 3 2 1  = 35
*/





