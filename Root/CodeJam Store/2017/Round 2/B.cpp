// Adjacency list implementation of Dinic's blocking flow algorithm.
// This is very fast in practice, and only loses to push-relabel flow.
//
// Running time:
//     O(|V|^2 |E|)
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain the actual flow values, look at all edges with
//       capacity > 0 (zero capacity edges are residual edges).

#include <bits/stdc++.h>

using namespace std;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

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

bool isPossible(int n, int c, int m, vector < pair <int, int> >& ticket, int mid) {
    int nodes = n + c + 2, source = 0, sink = n + c + 1;

    Dinic din(nodes);

    for (int i = 1; i <= c; i++) {
        din.AddEdge(source, i, INF);
    }

    for (int i = 1; i <= n; i++) {
        din.AddEdge(c + i, sink, mid);
    }

    for (int i = 2; i <= n; i++) {
        din.AddEdge(c + i, c + i - 1, INF);
    }

    for (int i = 0; i < m; i++) {
        din.AddEdge(ticket[i].second, c + ticket[i].first, 1);
    }

    return din.GetMaxFlow(source, sink) == m;
}

int main() {
    freopen("B-large-practice.in", "r", stdin);
    freopen("2.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, c, m;
        cin >> n >> c >> m;

        cerr << n << ' ' << m << ' ' << c << endl;

        vector < pair <int, int> > ticket(m);
        vector <int> cnt(n + 1, 0), frequency(c + 1, 0);

        for (auto &x: ticket) {
            cin >> x.first >> x.second;
            cnt[x.first]++;
            frequency[x.second]++;
        }

        int lo = *max_element(frequency.begin(), frequency.end()), hi = m, days;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (isPossible(n, c, m, ticket, mid)) {
                hi = mid - 1;
                days = mid;
            } else {
                lo = mid + 1;
            }
        }

        int cost = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > days) cost += cnt[i] - days;
        }

        cout << "Case #" << cs + 1 << ": " << days << " " << cost << endl;
    }

    return 0;
}

