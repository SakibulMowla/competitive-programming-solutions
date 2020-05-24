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

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>

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

    void ClearFlow() {
        for (int i = 0; i < N; ++i)
          for (int j = 0; j < G[i].size(); ++j)
            G[i][j].flow = 0;
    }
};



int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        double d;

        cin >> n >> d;

        Dinic D(2 * n + 1);
        vector <int> x(n + 1), y(n + 1);
        int penguins = 0;

        for (int i = 1; i <= n; i++) {
            int now, cap;
            cin >> x[i] >> y[i] >> now >> cap;
            penguins += now;
            D.AddEdge(0, i, now);
            D.AddEdge(i, i + n, cap);
        }

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (1.0 * (x[i] - x[j]) * (x[i] - x[j]) + 1.0 * (y[i] - y[j]) * (y[i] - y[j]) <= d * d) {
                    D.AddEdge(i + n, j, 1E9);
                    D.AddEdge(j + n, i, 1E9);
                }
            }
        }

        vector <int> ans;
        for (int i = 1; i <= n; i++) {
            if (D.GetMaxFlow(0, i) == penguins) ans.push_back(i);
            D.ClearFlow();
        }

        cout << "Case " << cs + 1 << ":";
        if (ans.size() == 0) cout << ' ' << -1;
        else for (int i = 0; i < ans.size(); i++) cout << ' ' << ans[i] - 1;
        cout << endl;
    }

    return 0;
}

