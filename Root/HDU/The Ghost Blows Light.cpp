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

#define SZ 110
#define SZ1 510

int dp[SZ][SZ1];
vector <pii> adj[SZ];
int val[SZ];
int n, t;

bool dfs (int u, int p) {
    if (u == n) return true;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i].X;
        if (v != p && dfs(v, u)) {
            t -= adj[u][i].Y;
            adj[u][i].Y = 0;
            return true;
        }
    }
    return false;
}

void solve (int u, int p) {
    for (int i = 0; i <= t; i++) {
        dp[u][i] = val[u];
    }
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i].X;
        if (v != p) {
            solve(v, u);
            int tym = 2 * adj[u][i].Y;
            for (int j = t; j >= tym; j--) {
                for (int k = 0; k <= j - tym; k++) {
                    dp[u][j] = max(dp[u][j], dp[v][k] + dp[u][j-tym-k]);
                }
            }
        }
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    while (cin >> n >> t) {
        for (int i = 1; i <= n; i++) {
            clr(adj[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }

        for (int i = 1; i <= n; i++) {
            cin >> val[i];
        }

        dfs(1, 0);

        if (t >= 0) {
            solve(1, 0);
            cout << dp[1][t] << endl;
        } else {
            cout << "Human beings die in pursuit of wealth, and birds die in pursuit of food!" << endl;
        }
    }

    return 0;
}







