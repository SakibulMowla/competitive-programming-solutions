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
    int cost, node, prio;
    data () {}
    data (int cost, int node, int prio): cost(cost), node(node), prio(prio) {}
    bool operator < (const data& x) const {
        return prio > x.prio;
    }
};

struct Graph {
    int n, maxlev;
    vector <int> par, val, ans, lev;
    vector < vector <int> > adj, cap, align;

    Graph (int n): n(n), par(n+2, -1), adj(n+2), val(n+2), cap(n+2, vector <int> (n+2, 0)), ans(n+2, 0), lev(n+2, 0), align(n+2), maxlev(0) {
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u - 1].pb(v - 1);
            adj[v - 1].pb(u - 1);
            cap[u - 1][v - 1] = w;
            cap[v - 1][u - 1] = w;
        }

        par[0] = 0;
        dfs(0);
        bfs();
    }

    void dfs (int u) {
        align[ lev[u] ].pb(u);
        maxlev = max(maxlev, lev[u]);
        for (int i = 0; i < sz(adj[u]); i++) {
            int v = adj[u][i];
            if (par[v] == -1) {
                par[v] = u;
                lev[v] = lev[u] + 1;
                dfs(v);
            }
        }
        return;
    }

    void bfs () {
        vector < priority_queue <data> > pq(n);
        for (int i = 1; i < n; i++) {
            pq[i].push(data(0, i, val[i]));
        }

        bool flag = true;
        int now = 1;

        while (flag) {
            flag = false;
            for (int i = 1; i <= maxlev; i++) {
                for (int j = 0; j < sz(align[i]); j++) {
                    int u = align[i][j];
                    int cnt = 0;
                    while (!pq[u].empty() && cnt < cap[u][ par[u] ]) {
                        flag = true;
                        int p = par[u];
                        data uu = pq[u].top(); pq[u].pop();
                        data vv = uu;
                        vv.cost = now;
                        pq[p].push(vv);
                        cnt++;
                    }
                }
            }
            ++now;
        }

        while (!pq[0].empty()) {
            data u = pq[0].top(); pq[0].pop();
            ans[u.node] = u.cost;
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << endl;

        return;
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    Graph Task(n);

    return 0;
}





