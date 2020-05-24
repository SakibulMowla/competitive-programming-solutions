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
};


int main () {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int r, c;
        cin >> r >> c;

        vector <int> row(r), col(c);

        for (int i = 0; i < r; i++) {
            cin >> row[i];
        }

        for (int i = r - 1; i > 0; i--) {
            row[i] -= row[i - 1];
        }

        for (int i = 0; i < c; i++) {
            cin >> col[i];
        }

        for (int i = c - 1; i > 0; i--) {
            col[i] -= col[i - 1];
        }

        Dinic din(r + c + 2);

        for (int i = 0; i < r; i++) {
            din.AddEdge(0, i + 1, row[i] - c);
        }

        for (int i = 0; i < c; i++) {
            din.AddEdge(r + i + 1, r + c + 1, col[i] - r);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                din.AddEdge(i + 1, r + j + 1, 19);
            }
        }

        din.GetMaxFlow(0, r + c + 1);

        vector < vector <int> > ans(r, vector <int> (c));

        for (int i = 1; i <= r; i++) {
            for (int j = 0; j < sz(din.G[i]); j++) {
                int v = din.G[i][j].to;
                if (v >= r + 1 && v <= r + c) {
                    ans[i - 1][v - r - 1] = din.G[i][j].flow + 1;
                }
            }
        }

        cout << "Matrix " << cs + 1 << endl;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (j) cout << ' ';
                cout << ans[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}



