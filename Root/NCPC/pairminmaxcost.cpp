#include <bits/stdc++.h>

using namespace std;

struct data {
    int a, b, c;
    data () {}
    data (int u, int v, int w): a(u), b(v), c(w) {}
    bool operator < (const data& x) const {
        return c < x.c;
    }
};

struct LCA {
    vector <vector <int>> lcapar, dist;
    vector <int> level;
    int LogN = 20;
    int Root;
    int n;

    LCA (vector < vector <pair < int, int> > >& tree, int n): n(n) {
        LogN = 2 + ceil(log2(n));
        lcapar = vector <vector <int>>(n + 2, vector <int>(LogN, -1));
        dist = vector <vector <int>>(n + 2, vector <int>(LogN, numeric_limits <int> :: min()));
        level = vector <int> (n + 2);

        if (tree[0].size()) Root = 0;
        else Root = 1;

        level[Root] = 0;
        lcapar[Root][0] = 0;
        LCADFS(Root, Root, tree);

        for (int i = 1; i <= LogN; i++) {
            for (int j = 0; j <= n; j++) {
                if (lcapar[j][i-1] != -1) {
                    dist[j][i] = max(dist[j][i-1], dist[lcapar[j][i-1]][i-1]);
                    lcapar[j][i] = lcapar[lcapar[j][i-1]][i-1];
                }
            }
        }

        return;
    }

    void LCADFS (int u, int p, vector < vector <pair < int, int> > >& tree) {
        for (int i = 0; i < tree[u].size(); i++) {
            int v = tree[u][i].first;
            int w = tree[u][i].second;
            if (v != p) {
                lcapar[v][0] = u;
                dist[v][0] = w;
                level[v] = level[u] + 1;
                LCADFS(v, u, tree);
            }
        }
        return;
    }

    int minMaxDist (int a, int b) {
        if (a == b) return 0;

        if (level[a] > level[b]) swap(a, b);
        int d = level[b] - level[a];

        int ans = numeric_limits <int> :: min();
        for (int i = 0; i < LogN; i++) {
            if (d & (1<<i)) {
                ans = max(ans, dist[b][i]);
                b = lcapar[b][i];
            }
        }

        if (a == b) return ans;

        for (int i = LogN - 1; i >= 0; i--) {
            if (lcapar[a][i] != lcapar[b][i] && lcapar[a][i] != -1 && lcapar[b][i] != -1) {
                ans = max(ans, dist[a][i]);
                ans = max(ans, dist[b][i]);
                a = lcapar[a][i];
                b = lcapar[b][i];
            }
        }

        ans = max(ans, dist[a][0]);
        ans = max(ans, dist[b][0]);

        return ans;
    }
};

struct MST {
    vector <int> par;

    MST (int n, int m, vector <data>& edges, vector < vector <pair < int, int> > >& tree): par(n + 1) {
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }

        sort(edges.begin(), edges.end());

        for (int i = 0; i < m; i++) {
            int x = Find(edges[i].a);
            int y = Find(edges[i].b);
            if (x != y) {
                par[x] = y;
                tree[edges[i].a].push_back({edges[i].b, edges[i].c});
                tree[edges[i].b].push_back({edges[i].a, edges[i].c});
            }
        }
    }

    int Find (int r) {
        return (r == par[r]? r: Find(par[r]));
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector < vector <pair < int, int> > > tree(n + 1, vector < pair <int, int> > ());
    vector <data> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(data(u, v, w));
    }

    MST mst(n, m, edges, tree);
    LCA lca(tree, n);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca.minMaxDist(u, v) << endl;
    }

    return 0;
}

/*
3 3
1 2 4
2 3 5
1 3 7

3
1 2
2 3
3 1


4 4
1 2 4
3 2 4
1 4 2
4 3 5

6
1 2
1 3
1 4
2 3
2 4
3 4
*/
