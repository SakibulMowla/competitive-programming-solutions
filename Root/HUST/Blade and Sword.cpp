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

#define SZ 210

char grid[SZ][SZ];
int dist[SZ][SZ];
int typ[SZ][SZ];
vector <pii> vv;
pii par[SZ][SZ];
int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, -1, 1};

int bfs (int r, int c, int sx, int sy, int ex, int ey) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            dist[i][j] = numeric_limits <int> ::max();
            typ[i][j] = 1;
        }
    }

    dist[sx][sy] = 0;
    queue <pii> Q;
    queue <int> q;
    queue <int> cn;
    Q.push({sx, sy});
    q.push(0);
    cn.push(3);
    bool flag = false;

    while (!Q.empty()) {
        pii u = Q.front(); Q.pop();
        int d = q.front(); q.pop();
        int ea = cn.front(); cn.pop();
//        cout << ">> " << u.X << " " << u.Y << endl;
//        if (d != dist[u.X][u.Y]) cout << "------->Here" << endl;
        if (u.X == ex && u.Y == ey) return d;

        if (grid[u.X][u.Y] == '*' && !flag) {
            flag = true;
            for (int i = 0; i < sz(vv); i++) {
                if (typ[vv[i].X][vv[i].Y] != 2) {
                    flag = false;
                    if (vv[i] == u) continue;
                    dist[vv[i].X][vv[i].Y] = dist[u.X][u.Y] + 1;
                    Q.push(vv[i]);
                    q.push(d+1);
                    cn.push(2);
                    par[vv[i].X][vv[i].Y] = u;
                    typ[vv[i].X][vv[i].Y] = 2;
                }
            }
        }
        if (grid[u.X][u.Y] != '*' || (grid[u.X][u.Y] == '*' && ea == 2)) {
            for (int i = 0; i < 4; i++) {
                pii v = {u.X + xx[i], u.Y + yy[i]};
                if (v.X >= 0 && v.X < r && v.Y >= 0 && v.Y < c && grid[v.X][v.Y] != '#' && typ[v.X][v.Y] == 1) {
                    dist[v.X][v.Y] = dist[u.X][u.Y] + 1;
                    Q.push(v);
                    q.push(d+1);
                    par[v.X][v.Y] = u;
                    typ[v.X][v.Y] = 3;
                    cn.push(3);
                }
            }
        }
    }

    return numeric_limits <int> :: max();
}

void path (pii p) {
    if (par[p.X][p.Y] == make_pair(-1, -1)) return;
    cout << ">> " << p.X << "  " << p.Y << endl;
    return path(par[p.X][p.Y]);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int r, c;
        cin >> r >> c;

        clr(vv);
        int sx, sy, ex, ey;

        for (int i = 0; i < r; i++) {
            cin >> grid[i];
            for (int j = 0; j < c; j++) {
                par[i][j] = {-1, -1};
                if (grid[i][j] == 'P') sx = i, sy = j;
                else if (grid[i][j] == 'D') ex = i, ey = j;
                else if (grid[i][j] == '*') vv.pb({i, j});
            }
        }

        int ans = bfs(r, c, sx, sy, ex, ey);

        cout << "Case " << cs + 1 << ": ";
        if (ans == numeric_limits <int> :: max()) cout << "impossible" << endl;
        else cout << ans << endl;
//        cout << dist[ex][ey] << endl;
    }


    return 0;
}







