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

struct Graph {
    int n, m, e, mask;
    set <pii> edges;

    Graph (int n, int m, int mask): n(n), m(m), e(0), mask(mask) {

    }

    void AddEdge (int a, int b) {
        edges.insert({min(a, b), max(a, b)});
        e++;
    }

    int connected () {
        vector < vector <int> > adj(n);
        vector <bool> vis(n, false);
        int compo = 0;

        for (auto it: edges) {
            adj[it.X].pb(it.Y);
            adj[it.Y].pb(it.X);
        }

        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 0) {
                return -1;
            }
        }

        queue <int> Q;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                compo++;
                Q.push(i);
                vis[i] = true;
                while (!Q.empty()) {
                    int u = Q.front(); Q.pop();
                    for (auto v: adj[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            Q.push(v);
                        }
                    }
                }
            }
        }

        return compo;
    }

    void Print () {
        for (auto it: edges) {
            cout << "-> " << it.X << ' ' << it.Y << endl;
        }
        cout << endl;
    }

    bool operator < (const Graph& x) const {
        return edges < x.edges;
    }
};

ll Generate (int n, int k, int m) {
    set <Graph> ms;

    for (int mask = 0; mask < (1<<n); mask++) {
        vector <pii> edges;
        for (int i = 0; i < n; i++) if (mask & (1<<i)) {
            for (int j = 0; j < n; j++) if (!(mask & (1<<j))) {
                edges.pb({i, j});
            }
        }
        int lim = edges.size();
        for (int imask = 0; imask < (1<<lim); imask++) {
            Graph g(n, __builtin_popcount(mask), mask);
            for (int i = 0; i < lim; i++) if (imask & (1<<i)) {
                g.AddEdge(edges[i].X, edges[i].Y);
            }
            if (g.connected() == k && g.m == m) {
                ms.insert(g);
            }
        }
    }

    ll ans = 0;
    for (auto it: ms) {
        ans += (1<< it.e);
        if (it.mask == 7)
            it.Print();
    }

    cout << ms.size() << endl;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

//    for (int i = 1; i <= 5; i++) {
//        for (int j = 1; j <= i; j++) {
//            cout << ">> " << j << ' ' << i - j << ' ' << Generate(i, 1, j) << endl;
//        }
//    }

    Generate(5, 1, 3);

    return 0;
}




