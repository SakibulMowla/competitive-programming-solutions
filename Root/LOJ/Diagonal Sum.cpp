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

vector <int> val(210);
int mp[210][210][2];
int rmp[210][210][2];
int ans[55][55];

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= 2 * (n + m - 1); i++) {
            cin >> val[i];
        }

        Dinic din(2 * (n + m - 1) + 2);

        int node = 0;

        //cerr << "Here" << endl;

        for (int i = 1; i <= n; i++) {
            int x = i;
            int y = 1;
            node++;
            while (x >= 1 && y <= m) {
                mp[x][y][0] = node;
                val[node]--;
//                din.AddEdge(0, node, INF);
                x--;
                y++;
            }
        }

        //cerr << "Here1" << endl;

        for (int i = 2; i <= m; i++) {
            int x = n;
            int y = i;
            node++;
            while (x >= 1 && y <= m) {
                mp[x][y][0] = node;
                val[node]--;
//                din.AddEdge(0, node, INF);
                x--;
                y++;
            }
        }

        //cerr << "Here2" << endl;

        for (int i = 1; i <= n; i++) {
            int x = i;
            int y = m;
            node++;
            while (x >= 1 && y >= 1) {
                mp[x][y][1] = node;
                val[node]--;
//                din.AddEdge(node, 2 * (n + m - 1) + 1, INF);
                x--;
                y--;
            }
        }

        //cerr << "Here3" << endl;

        for (int i = m - 1; i >= 1; i--) {
            int x = n;
            int y = i;
            node++;
            while (x >= 1 && y >= 1) {
                mp[x][y][1] = node;
                val[node]--;
//                din.AddEdge(node, 2 * (n + m - 1) + 1, INF);
                x--;
                y--;
            }
        }

        //cerr << "Here4" << endl;

        for (int i = 1; i <= 2 * (n + m - 1); i++) {
            if (i <= n + m - 1) din.AddEdge(0, i, val[i]);
            else din.AddEdge(i, 2 * (n + m - 1) + 1, val[i]);
        }

        //cerr << "Here5" << endl;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                //cerr << "i, j = " << i << ' ' << j << " mp = " << mp[i][j][0] << ' ' << mp[i][j][1] << endl;
                rmp[mp[i][j][0]][mp[i][j][1]][0] = i;
                rmp[mp[i][j][0]][mp[i][j][1]][1] = j;
                din.AddEdge(mp[i][j][0], mp[i][j][1], 99);
            }
        }

        //cerr << "Here6" << endl;

        din.GetMaxFlow(0, 2 * (n + m - 1) + 1);

        for (int i = 1; i <= 2 * (n + m - 1); i++) {
            for (int j = 0; j < sz(din.G[i]); j++) {
                int v = din.G[i][j].to;
                if (v >= 1 && v <= 2 * (n + m - 1)) {
                    ans[rmp[i][v][0]][rmp[i][v][1]] = din.G[i][j].flow;
                }
            }
        }

        cout << "Case " << cs + 1 << ":" << endl;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << ans[i][j] + 1;
                if (j < m) cout << ' ';
                assert(ans[i][j]+1 >= 1 && ans[i][j]+1 <= 100);
            }
            cout << endl;
        }
    }


    return 0;
}







