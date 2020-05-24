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

#define SZ 200010

vector <int> adj[SZ];
bool vis[SZ];
int col[SZ];

int dfs (int u) {
    vis[u] = 1;
    int ret = 1;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (!vis[v] && col[u] != col[v]) {
            ret += dfs(v);
        }
    }
    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, m, c;
    cin >> n >> m >> c;

    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ll tmp = dfs(i);
            ans += tmp * (tmp - 1LL) / 2LL;
        }
    }

    cout << ans << endl;


    return 0;
}







