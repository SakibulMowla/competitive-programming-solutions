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

using pdd = pair <double, double>;
using pid = pair <int, double>;
using pii = pair <int, int>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 1010

struct data {
    int u, v;
    double w;
    data () {}
    data (int a, int b, double c) {
        u = a, v = b, w = c;
    }
};

bool comp (data p, data q) {
    return p.w < q.w;
}

double dist (pdd a, pdd b) {
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

int par[SZ];

int Find (int r) {
    if (r == par[r]) return r;
    return par[r] = Find(par[r]);
}

vector <pid> adj[SZ];

pii mdl[SZ][SZ];

void dfs (int gp, int p, int u, pii now, double best) {
    mdl[gp][u] = now;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i].X;
        if (v != p) {
            pii tnow = now;
            double tbest = best;
            if (adj[u][i].Y > best) {
                tbest = adj[u][i].Y;
                tnow = {u, v};
            }
            dfs(gp, u, v, tnow, tbest);
        }
    }
    return;
}

int main() {
//    #if defined JESI
        freopen("froggy.in", "r", stdin);
        freopen("froggy.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    double w;
    int n;

    cin >> w >> n;

    vector <pdd> pnts(n);

    for (int i = 0; i < n; i++) {
        cin >> pnts[i].X >> pnts[i].Y;
    }

    vector <data> edge;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edge.pb(data(i, j, dist(pnts[i], pnts[j])));
        }
    }
    sort(edge.begin(), edge.end(), comp);

    for (int i = 0; i < n; i++) {
        par[i] = i;
    }

    for (int i = 0; i < sz(edge); i++) {
        int a = Find(edge[i].u);
        int b = Find(edge[i].v);
        if (a != b) {
            par[a] = b;
            adj[edge[i].u].pb({edge[i].v, edge[i].w});
            adj[edge[i].v].pb({edge[i].u, edge[i].w});
        }
    }

    for (int i = 0; i < n; i++) {
        dfs(i, i, i, {i, i}, 0);
    }

    pdd ans = {w / 2.0, 0};
    double best = 1e18;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a = mdl[i][j].X;
            int b = mdl[i][j].Y;

            double d1 = pnts[a].X;
            double d3 = (w - pnts[b].X);
            double d2 = sqrt(dist(pnts[a], pnts[b]));

            if (max(d1 / 2.0, max(d2, d3)) <= best) {
                best = max(d1 / 2.0, max(d2, d3));
                ans.X = pnts[a].X / 2.0;
                ans.Y = pnts[a].Y;
            }
            if (max(d2 / 2.0, max(d1, d3)) <= best) {
                best = max(d2 / 2.0, max(d1, d3));
                ans.X = (pnts[a].X + pnts[b].X) / 2.0;
                ans.Y = (pnts[a].Y + pnts[b].Y) / 2.0;
            }
            if (max(d3 / 2.0, max(d1, d2)) <= best) {
                best = max(d3 / 2.0, max(d1, d2));
                ans.X = pnts[b].X + (w - pnts[b].X) / 2.0;
                ans.Y = pnts[b].Y;
            }
        }
    }

    cout << ans.X << ' ' << ans.Y << endl;
//    cerr << best << endl;

    return 0;
}





