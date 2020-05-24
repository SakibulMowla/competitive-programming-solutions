#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define sz(x) (int)x.size()
#define pb push_back

#define X first
#define Y second

using pii = pair <int, int>;

struct Graph {
    int n, m;
    vector < vector <int> > adj, P;
    vector <pii> edge;
    map <pii, ll> mp;
    vector <int> level, papa;
    vector <ll> cost;

    Graph (int n, int m): n(n), m(m), adj(n), edge(n-1), level(n, 0), P(n, vector <int> (20, -1)), cost(n), papa(n) {
        for (int i = 0; i < n; i++) {
            papa[i] = i;
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            --u, --v;
            adj[u].pb(v);
            adj[v].pb(u);
            edge[i] = {min(u, v), max(u, v)};
            mp[{min(u, v), max(u, v)}] = w;
        }

        BuildNewGraph();
        LCA();

        for (int i = 0; i < n - 1; i++) {
            if (mp[edge[i]] == 1) {
                Eliminate(edge[i].X, edge[i].Y);
            }
        }

        for (int i = 0; i < m; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                int u, v;
                ll w;
                cin >> u >> v >> w;
                --u, --v;
                cout << FindAns(u, v, LCAPoint(u, v), w) << endl;
            } else {
                int p;
                ll c;
                cin >> p >> c;
                if (level[edge[p-1].X] > level[edge[p-1].Y]) {
                    cost[edge[p-1].X] = c;
                } else {
                    cost[edge[p-1].Y] = c;
                }
                if (c == 1) {
                    Eliminate(edge[p-1].X, edge[p-1].Y);
                }
            }
        }
    }

    void BuildNewGraph (int u = 0, int p = 0) {
        for (auto v: adj[u]) {
            if (v != p) {
                level[v] = level[u] + 1;
                P[v][0] = u;
                cost[v] = mp[{min(u, v), max(u, v)}];
                BuildNewGraph(v, u);
            }
        }
        return;
    }

    void LCA () {
        for (int j = 1; j < 19; j++) {
            for (int i = 0; i < n; i++) {
                if (P[i][j-1] != -1) {
                    P[i][j] = P[P[i][j-1]][j-1];
                }
            }
        }
        return;
    }

    int LCAPoint (int u, int v) {
        if (level[v] > level[u]) swap(u, v);
        for (int i = 18; i >= 0; i--) {
            if (level[u] - (1 << i) >= level[v]) {
                u = P[u][i];
            }
        }
        if (u == v) return u;
        for (int i = 18; i >= 0; i--) {
            if (P[u][i] != -1 && P[v][i] != -1 && P[u][i] != P[v][i]) {
                u = P[u][i];
                v = P[v][i];
            }
        }
        return P[u][0];
    }

    void Eliminate (int u, int v) {
        if (level[u] > level[v]) swap(u, v);
        papa[v] = u;
        return;
    }

    int Find (int r) {
        if (r == papa[r]) return r;
        return papa[r] = Find(papa[r]);
    }

    ll FindAns (int u, int v, int meet, ll w) {
        u = Find(u);
        while (level[u] > level[meet]) {
            w /= cost[u];
            if (w == 0) {
                return 0;
            }
            u = Find(P[u][0]);
        }
        u = v;
        u = Find(u);
        while (level[u] > level[meet]) {
            w /= cost[u];
            if (w == 0) {
                return 0;
            }
            u = Find(P[u][0]);
        }
        return w;
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    Graph task(n, m);

    return 0;
}


