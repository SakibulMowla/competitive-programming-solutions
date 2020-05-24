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
const int inf = 1E6;
const ll mod = 1E9;

#define SZ 1010

vector <pii> adj[SZ];
int mid;

int dfs (int u, int p) {
    int tot = 0;
    bool flag = false;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i].X;
        if (v != p) {
            flag = true;
            if (adj[u][i].Y <= mid) {
                tot += min(adj[u][i].Y, dfs(v, u));
            } else {
                tot += dfs(v, u);
            }
        }
    }
    if (flag) return min(inf, tot);
    return inf;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m && (n + m)) {
        for (int i = 1; i <= n; i++) {
            clr(adj[i]);
        }

        int hi = 0;

        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
            hi = max(hi, w);
        }

        int lo = 1, ans = -1;

        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            if (dfs(1, 0) <= m) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << endl;
    }


    return 0;
}







