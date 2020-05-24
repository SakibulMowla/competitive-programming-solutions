// From Stanford ACM Notebook
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
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <algorithm>
#include <numeric>

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

struct Solution {
    struct Data {
        int u, v, c, p, e;
        Data() {}
        Data(int u, int v, int c, int p, int e) :
            u(u), v(v), c(c), p(p), e(e) {}
        bool operator < (const Data& x) const {
            return p < x.p;
        }
    };

    int n, d, m;
    vector<Data> flights;
    vector<int> participants;

    Solution(int n, int d, int m) :
        n(n), m(m), d(d), flights(m), participants(n) {
        for (auto &data: flights) {
            cin >> data.u >> data.v >> data.c >> data.p >> data.e;
        }
        sort(flights.begin(), flights.end());
        for (auto &p: participants) {
            cin >> p;
        }
    }


    int getNode(int city, int day) {
        return city + day * n;
    }

    bool check(int lim) {
        int source = getNode(0, 0);
        int sink = getNode(n, d);

        Dinic din(n * d + n + 2);
        
        for (int i = 0; i < n; i++) {
            din.AddEdge(source,
                        getNode(i + 1, 0),
                        participants[i]);
        }

        for (int i = 0; i <= lim; i++) {
            din.AddEdge(getNode(flights[i].u, flights[i].e),
                        getNode(flights[i].v, flights[i].e + 1),
                        flights[i].c);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < d; j++) {
                din.AddEdge(getNode(i, j),
                            getNode(i, j + 1),
                            INF);
            }
        }

        return din.GetMaxFlow(source, sink) ==
               accumulate(participants.begin(), participants.end(), 0);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, d, m;
        cin >> n >> d >> m;

        Solution sol(n, d, m);

        int lo = 0, hi = m - 1, ans = INF;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (sol.check(mid)) {
                ans = sol.flights[mid].p;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << "Case #" << cs + 1 << ": " << (ans == INF ? "Impossible" : to_string(ans)) << endl;
    }

    return 0;
}
