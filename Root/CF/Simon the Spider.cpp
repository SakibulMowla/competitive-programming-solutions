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

#define SZ 100010

struct data {
    int u, v;
    ll w;
};

bool comp (data a, data b) {
    return a.w < b.w;
}

struct LCA {
    int n, m;
    vector < vector <pll> > adj;
    vector <int> level;
    vector < vector <int> > P;
    vector < vector <ll> > cost;

    LCA (int n, int m, vector < vector <pll> >& adj): n(n), m(m), adj(adj), level(n), P(n + 2, vector <int> (20, -1)), cost(n + 2, vector <ll> (20, 0)) {
        level[0] = 0;
        cost[0][0] = 0;
        dfs(0, 0);

        for (int i = 1; i < 15; i++) {
            for (int j = 0; j < n; j++) {
                if (P[j][i-1] != -1) {
                    P[j][i] = P[P[j][i-1]][i-1];
                    cost[j][i] = max(cost[j][i-1], cost[P[j][i-1]][i-1]);
                }
            }
        }
    }

    void dfs (int u, int p) {
        for (int i = 0; i < sz(adj[u]); i++) {
            int v = adj[u][i].X;
            if (v != p) {
                level[v] = level[u] + 1;
                cost[v][0] = adj[u][i].Y;
                P[v][0] = u;
                dfs(v, u);
            }
        }
        return;
    }

    ll FindMax (int a, int b) {
        if (level[a] < level[b]) swap(a, b);

        ll ans = 0;

        for (int i = 15; i >= 0; i--) {
            if (level[a] - (1<<i) >= level[b]) {
                ans = max(ans, cost[a][i]);
                a = P[a][i];
            }
        }

        if (a == b) {
            return ans;
        }

        for (int i = 15; i >= 0; i--) {
            if (P[a][i] != -1 && P[b][i] != -1 && P[a][i] != P[b][i]) {
                ans = max(ans, max(cost[a][i], cost[b][i]));
                a = P[a][i];
                b = P[b][i];
            }
        }

        ans = max(ans, max(cost[a][0], cost[b][0]));

        return ans;
    }
};

struct Solve {
    int n, m;
    vector < vector <pll> > adj;
    vector <data> edges;
    vector <int> par;

    Solve (int n, int m): n(n), m(m), adj(n), edges(m), par(n) {
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            edges[i].u--;
            edges[i].v--;
        }

        ll ans = MST();
        if (ans == -1) {
            cout << "disconnected" << endl;
        } else {
            ll best = ans;

            LCA Tree(n, m, adj);

            for (int i = m - 1; i >= 0; i--) {
                best = min(best, ans - edges[i].w - Tree.FindMax(edges[i].u, edges[i].v));
            }

            cout << best << endl;
        }
    }

    int Find (int r) {
        if (r == par[r]) return r;
        return par[r] = Find(par[r]);
    }

    ll MST () {
        sort(edges.begin(), edges.end(), comp);

        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        int cnt = 0;
        ll ans = 0;

        for (int i = 0; i < m; i++) {
            int x = Find(edges[i].u);
            int y = Find(edges[i].v);
            if (x != y) {
                par[x] = y;
                cnt++;
                ans += edges[i].w;
                adj[edges[i].u].pb({edges[i].v, edges[i].w});
                adj[edges[i].v].pb({edges[i].u, edges[i].w});
            }
        }

        if (cnt != n-1) ans = -1;
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        Solve Task(n, m);
    }

    return 0;
}


/*
3 1
1 2 5
4 5
1 2 5
2 3 6
3 4 8
3 4 4
1 4 2
*/


