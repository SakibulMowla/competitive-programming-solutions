#include <bits/stdc++.h>

using namespace std;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

using ll = long long;

const int INF = 2000000000;

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};

bool flag[110];

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

    void dfs (int u) {
        flag[u] = true;
        for (int i = 0; i < sz(G[u]); i++) {
            int j = G[u][i].to;
            if (!flag[j] && G[u][i].flow) {
                dfs(j);
            }
        }
    }
};


int main() {
    freopen("hentium.in", "r", stdin);
    freopen("hentium.out", "w", stdout);

    ios_base::sync_with_stdio(false);

    int n;
    while (cin >> n && n) {
        Dinic din(n + 2);

        int v[n+2][2];

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            din.AddEdge(0, i + 1, a);
            din.AddEdge(i + 1, n + 1, b);
            v[i+1][0] = a;
            v[i+1][1] = b;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                if (i != j) din.AddEdge(i + 1, j + 1, x);
            }
        }

        ll ans = din.GetMaxFlow(0, n + 1);

//        vector <bool> flag(n + 1, false);
//
//        for (int i = 0; i < sz(din.G[0]); i++) {
//            if (din.G[0][i].cap != din.G[0][i].flow) {
//                flag[din.G[0][i].to] = true;
//            }
//        }
//
//        for (int i = 1; i <= n; i++) {
//            for (int j = 0; j < sz(din.G[i]); j++) {
//                int v = din.G[i][j].to;
//                if (din.G[i][j].to == n + 1 && din.G[i][j].cap == din.G[i][j].flow) {
//                    flag[i] = true;
//                }
//            }
//        }

        mem(flag, false);

        ll flow[n+2][2];
        mem(flow, 0);

        for (int i = 0; i < sz(din.G[0]); i++) {
            flow[din.G[0][i].to][0] = din.G[0][i].flow;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < sz(din.G[i]); j++) {
                if (din.G[i][j].to == n + 1) {
                    flow[i][1] = din.G[i][j].flow;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (flow[i][0] == v[i][0] && flow[i][1] == v[i][1]) {
                if (v[i][0] > v[i][1]) {
                    flag[i] = true;
                }
            }
            else if (flow[i][0] == v[i][0]) {
                flag[i] = true;
            }
        }

        cout << ans << endl;
//        for (int i = 1; i <= n; i++) {
//            if (i - 1) cout << ' ';
//            cout << (flag[i] ? 2 : 1);
//        }
        for (int i = 1; i <= n; i++) {
            if (i - 1) cout << ' ';
            cout << (flag[i] ? 1 : 2);
        }
        cout << endl;
    }

    return 0;
}








