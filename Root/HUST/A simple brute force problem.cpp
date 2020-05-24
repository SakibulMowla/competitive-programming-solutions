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

#define SZ 100010

const int INF = 2000000000;

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0) {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if (!e) {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

void dfs (int u, vector < vector <int> > &adj, vector <bool> &vis) {
    if (vis[u] == true) {
        return;
    }
    vis[u] = true;
    for (auto v:adj[u]) {
        dfs(v, adj, vis);
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        int nodes = n + m + 2;
        int src = 0;
        int snk = nodes - 1;

        Dinic din(nodes);
        int profit = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            profit += x;
            din.AddEdge(src, i + 1, x);
        }

        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            din.AddEdge(n + j + 1, snk, x);
        }

        vector < vector <int> > dep (n);

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                dep[i].pb(x);
            }
        }

        vector < vector <int> > adj(m);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                if (x) {
                    adj[i].pb(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            vector <bool> vis(m, false);
            for (int j = 0; j < sz(dep[i]); j++) {
                dfs (dep[i][j], adj, vis);
            }
            for (int j = 0; j < m; j++) {
                if (vis[j]) {
                    din.AddEdge(i + 1, n + j + 1, 1E7);
                }
            }
        }

        cout << "Case #" << cs + 1 << ": ";
        cout << profit - din.GetMaxFlow(src, snk) << endl;
    }


    return 0;
}



