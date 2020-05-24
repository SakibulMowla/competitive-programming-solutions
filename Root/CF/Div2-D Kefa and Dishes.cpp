#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;

using VL = vector <ll>;
using VVL = vector <VL>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010

ll solve (int prev, int mask, int &n, int &m, VL &a, VVL &mat, VVL &dp) {
    if (__builtin_popcount(mask) == m) return 0;

    ll &ret = dp[prev][mask];
    if (~ret) return ret;

    ret = 0;
    for (int i = 0; i < n; i++) if (!(mask & (1<<i))) {
        ret = max(ret, a[i] + solve(i, mask | (1<<i), n, m, a, mat, dp) + (mask? mat[prev][i]: 0));
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    VL a(n);

    for (auto &x: a) {
        cin >> x;
    }

    VVL mat(n, VL(n, 0));

    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u-1][v-1] = w;
    }

    VVL dp(n, VL(1<<n, -1));

    cout << solve (0, 0, n, m, a, mat, dp) << endl;

    return 0;
}


