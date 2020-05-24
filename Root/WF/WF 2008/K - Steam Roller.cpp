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
const int inf = 2E9;
const ll mod = 1E9;

#define SZ 110

vector <pii> adj[SZ][SZ];
vector <int> cost[SZ][SZ];

int xx[] = {-1, 1, 0, 0};
int yy[] = {0, 0, -1, 1};

struct data {
    int nr, nc, val, doubled, last, dir; ///current row, current column, cost so far, was the last edge cost doubled, cost of last edge
    bool operator < (const data& p) const {
        return val > p.val;
    }
};

int dist[SZ][SZ][5][2];

inline int decideDir (int a, int b, int c, int d) {
    if (a == c) {
        if (b > d) return 0;
        return 3;
    } else {
        if (a > c) return 1;
        return 2;
    }
}

int bfs (int R, int C, int r1, int c1, int r2, int c2) {
    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= C; j++) {
            for (int k = 0; k < 5; k++) {
                dist[i][j][k][0] = dist[i][j][k][1] = inf;
            }
        }
    }
    dist[r1][c1][4][1] = 0;

    priority_queue <data> pq;
    pq.push({r1, c1, 0, 0, 0, 4});

    int best = inf;

    while (!pq.empty()) {
        data u = pq.top(); pq.pop();

        if (u.nr == r2 && u.nc == c2) {
            if (u.doubled) best = min(best, u.val);
            else best = min(best, u.val + u.last);
        }

//        cout << ">> " << u.nr << ' ' << u.nc << '\n';

        for (int i = 0; i < sz(adj[u.nr][u.nc]); i++) {
            int tr = adj[u.nr][u.nc][i].X;
            int tc = adj[u.nr][u.nc][i].Y;

            int tdir = decideDir(u.nr, u.nc, tr, tc);

//            cout << ">>> tr tc tdir " <<  tr << ' ' << tc << ' ' << tdir << '\n';

            int dbl = 0;
            if (tdir != u.dir) {
                dbl = 1;
            }

            data v;
            v.nr = tr;
            v.nc = tc;
            v.val = u.val + cost[u.nr][u.nc][i] * (dbl ? 2 : 1) + ((u.dir != tdir && u.doubled == 0) ? u.last : 0);
            v.doubled = dbl;
            v.last = cost[u.nr][u.nc][i];
            v.dir = tdir;

//            cout << "Dist = " << dist[tr][tc][tdir] << ' ' << v.val << '\n';

            if (dist[tr][tc][tdir][dbl] > v.val) {
//                cout << ">> Here\n";
                dist[tr][tc][tdir][dbl] = v.val;
                pq.push(v);
            }
        }
    }

    return best == inf ? -1 : best;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test = 0;
    int R, C, r1, r2, c1, c2;

    while (scanf("%d %d %d %d %d %d", &R, &C, &r1, &c1, &r2, &c2) == 6 && (R || C || r1 || c1 || r2 || c2)) {
        for (int i = 0; i <= R; i++) {
            for (int j = 0; j <= C; j++) {
                clr(adj[i][j]);
                clr(cost[i][j]);
            }
        }

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j < C; j++) {
                int x;
                scanf("%d", &x);
                if (x) {
                    adj[i][j].pb({i, j+1});
                    adj[i][j+1].pb({i, j});
                    cost[i][j].pb(x);
                    cost[i][j+1].pb(x);
                }
            }
            if (i < R)
            for (int j = 1; j <= C; j++) {
                int x;
                scanf("%d", &x);
                if (x) {
                    adj[i][j].pb({i+1, j});
                    adj[i+1][j].pb({i, j});
                    cost[i][j].pb(x);
                    cost[i+1][j].pb(x);
                }
            }
        }

        int k = bfs(R, C, r1, c1, r2, c2);

        if (k == -1) printf("Case %d: Impossible\n", ++test);
        else printf("Case %d: %d\n", ++test, k);
    }


    return 0;
}







