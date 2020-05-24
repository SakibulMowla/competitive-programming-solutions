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
const int inf = 1E9;
const ll mod = 1E9;

#define SZ 2010

struct data {
    int u, v, w;
};

data edge[SZ];
vector <int> adj[SZ];
int dist[SZ];
bool vis[SZ];

bool dfs (int u) {
    vis[u] = true;
    if (u == 0) return true;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            if (dfs(v)) {
                return true;
            }
        }
    }
    return false;
}

int bellman_ford (int n, int m) {
    for (int i = 0; i < n; i++) {
        dist[i] = inf;
    }
    dist[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[edge[j].u] + edge[j].w < dist[edge[j].v]) {
                dist[edge[j].v] = dist[edge[j].u] + edge[j].w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (dist[edge[j].u] + edge[j].w < dist[edge[j].v]) {
            memset(vis, 0, sizeof(bool) * (n+2));
            if (dfs(edge[j].v)) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            clr(adj[i]);
        }

        for (int i = 0; i < m; i++) {
            cin >> edge[i].u >> edge[i].v >> edge[i].w;
            adj[edge[i].u].pb(edge[i].v);
        }

        if (bellman_ford(n, m)) cout << "Case #" << cs + 1 << ": possible" << endl;
        else cout << "Case #" << cs + 1 << ": not possible" << endl;
    }


    return 0;
}







