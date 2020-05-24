#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 2E9;
const ll mod = 1LL;

#define SZ  1010

int xx[] = {-1, 1, 0, 0};
int yy[] = {0, 0, -1, 1};

int r, c;
char grid[SZ][SZ];
bool vis[SZ][SZ];
int dists[SZ][SZ];
int distp[SZ][SZ];
int distb[SZ][SZ];

struct data {
    int x, y, c;
    data (int a, int b, int _c) {
        x = a, y = b, c = _c;
    }
    bool operator < (const data& p) const {
        return c > p.c;
    }
};

void bfs (int sx, int sy, int dist[][SZ]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            dist[i][j] = inf;
            vis[i][j] = 0;
        }
    }
    dist[sx][sy] = 0;
    vis[sx][sy] = 1;
    priority_queue <data> pq;
    pq.push(data(sx, sy, 0));
    while (!pq.empty()) {
        data u = pq.top(); pq.pop();
        for (int i = 0; i < 4; i++) {
            int p = u.x + xx[i];
            int q = u.y + yy[i];
            if (p >= 0 && p < r && q >= 0 && q < c && !vis[p][q] && dist[p][q] > dist[u.x][u.y] + (grid[p][q] == '#')) {
                vis[p][q] = 1;
                dist[p][q] = dist[u.x][u.y] + (grid[p][q] == '#');
                pq.push(data(p, q, dist[p][q]));
            }
        }
    }
    return;
}

void bfs1 (int dist[][SZ]) {
    priority_queue <data> pq;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            vis[i][j] = 0;
            dist[i][j] = inf;
        }
    }
    for (int i = 0; i < c; i++) {
        pq.push(data(0, i, grid[0][i] == '#'));
        vis[0][i] = 1;
        dist[0][i] = (grid[0][i] == '#');
        pq.push(data(r-1, i, grid[r-1][i] == '#'));
        vis[r-1][i] = 1;
        dist[r-1][i] = (grid[r-1][i] == '#');
    }
    for (int i = 0; i < r; i++) {
        pq.push(data(i, 0, grid[i][0] == '#'));
        vis[i][0] = 1;
        dist[i][0] = (grid[i][0] == '#');
        pq.push(data(i, c-1, grid[i][c-1] == '#'));
        vis[i][c-1] = 1;
        dist[i][c-1] = (grid[i][c-1] == '#');
    }
    while (!pq.empty()) {
        data u = pq.top(); pq.pop();
        for (int i = 0; i < 4; i++) {
            int p = u.x + xx[i];
            int q = u.y + yy[i];
            if (p >= 0 && p < r && q >= 0 && q < c && !vis[p][q] && dist[p][q] > dist[u.x][u.y] + (grid[p][q] == '#')) {
                vis[p][q] = 1;
                dist[p][q] = dist[u.x][u.y] + (grid[p][q] == '#');
                pq.push(data(p, q, dist[p][q]));
            }
        }
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    scanf("%d %d", &r, &c);

    int sx, sy, px, py;

    for (int i = 0; i < r; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'S') sx = i, sy = j;
            else if (grid[i][j] == 'P') px = i, py = j;
        }
    }

    bfs(sx, sy, dists);
    bfs(px, py, distp);
    bfs1(distb);

    int ans = inf;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '#') ans = min(ans, dists[i][j] + distp[i][j] + distb[i][j] - 2);
            else ans = min(ans, dists[i][j] + distp[i][j] + distb[i][j]);
        }
    }

    printf("%d\n",ans);

    return 0;
}


