#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);


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

#define SZ 210

bool prime[20010];

void sieve () {
    int k = sqrt(20010);
    for (int i = 3; i <= k; i++) {
        if (!prime[i]) {
            for (int j = i * i; j < 20001; j += i + i) {
                prime[j] = 1;
            }
        }
    }
    return;
}

int a[SZ];
vector <int> adj[SZ];
vector < vector <int> > ans;
vector <int> tmp;
bool vis[SZ];

void dfs (int u) {
    vis[u] = 1;
    tmp.pb(u);
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v);
            return;
        }
    }
    return;
}

inline bool chk(int x, int n) {
    return (x>=1 && x<=n);
}

int main() {
    FAST

    sieve();

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Dinic din(n+2);

    for (int i = 1; i <= n; i++) {
        if (a[i] & 1) {
            din.AddEdge(0, i, 2);
            for (int j = 1; j <= n; j++) {
                if (a[j]%2 == 0 && !prime[ a[i]+a[j] ]) {
                    din.AddEdge(i, j, 1);
                }
            }
        } else {
            din.AddEdge(i, n+1, 2);
        }
    }

    if (din.GetMaxFlow(0, n+1) != n) {
        cout << "Impossible\n";
    } else {
        /// Edges with flow on them
        for (int i = 0; i < sz(din.G); i++) {
            for (int j = 0; j < sz(din.G[i]); j++) {
                if (din.G[i][j].flow && chk(din.G[i][j].from, n) && chk(din.G[i][j].to, n)) {
                    adj[din.G[i][j].from].pb(din.G[i][j].to);
                }
            }
        }

        /// Finding Chunks
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                clr(tmp);
                dfs(i);
                ans.pb(tmp);
            }
        }

        /// Printing Answer
        cout << sz(ans) << '\n';
        for (int i = 0; i < sz(ans); i++) {
            cout << sz(ans[i]);
            for (int j = 0; j < sz(ans[i]); j++) {
                cout << ' ' << ans[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}






