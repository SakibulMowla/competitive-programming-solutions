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
#include <time.h>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E6;
const ll mod = 1LL;

#define SZ  150

int grid[SZ][SZ];
pii rev[SZ*SZ];

int x[] = {1, 0, -1, 0};
int y[] = {0, -1, 0, 1};

void Generate () {
    memset(grid, -1, sizeof grid);
    for (int i = 1; i <= 140; i++) for (int j = 1; j <= 140; j++) grid[i][j] = 0;
    int nx = 0, ny = 140, dir = 0, val = 140*140;
    while (true) {
        while (true) {
            if (nx+x[dir] < 0 || ny+y[dir] < 0) break;
            if (grid[nx+x[dir]][ny+y[dir]]) break;
            nx += x[dir];
            ny += y[dir];
            assert(nx>=1&&nx<=140);
            assert(ny>=1&&ny<=140);
            rev[val] = make_pair(nx, ny);
            grid[nx][ny] = val--;
            if (val == 0) break;
        }
//        cout << "val = " << val << endl;
        if (val == 0) break;
        dir = (dir + 1) % 4;
    }
    return;
}

int prime[SZ*SZ];

void sieve () {
    prime[1] = 1;
//    for (int i = 4; i <= 10000; i += 2)
//        prime[i] = 1;
    for (int i = 2; i <= 140*140; i++) {
        if (!prime[i]) {
            for (int j = i + i; j <= 140*140; j += i) {
                prime[j] = 1;
            }
        }
    }
//    for (int i = 1; i <= 100; i++) if (!prime[i]) cout << i << ' ' ;
    return;
}

int dist[SZ][SZ];

int bfs (pii a, pii b) {
    if (a == b) return 0;

    for (int i = 1; i <= 140; i++) {
        for (int j = 1; j <= 140; j++) {
            dist[i][j] = inf;
        }
    }

    queue <int> Q;
    Q.push(a.X);
    Q.push(a.Y);
    dist[a.X][a.Y] = 0;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int v = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nu = u + x[i];
            int nv = v + y[i];
            if (nu >= 1 && nu <= 140 && nv >= 1 && nv <= 140 && dist[nu][nv] > dist[u][v] + 1 && prime[ grid[nu][nv] ]) {
                dist[nu][nv] = dist[u][v] + 1;
                Q.push(nu);
                Q.push(nv);
            }
        }
    }

    if (dist[b.X][b.Y] >= inf) return -1;
    return dist[b.X][b.Y];
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    freopen("1.txt", "w", stdout);

//    ios::sync_with_stdio(false);

    Generate();
//    cout << "here\n";
    sieve();

//    for (int i = rev[1].Y + 5; i >= rev[1].Y - 5; i--) {
//        for (int j = rev[1].X - 5; j <= rev[1].X + 5; j++) {
////            cout << grid[j][i] << ' ';
//            printf("%3d ", grid[j][i]);
//        }
//        cout << endl;
//    }

    int cs = 0, a, b;

    while (cin >> a >> b) {
        cout << "Case " << ++cs << ": ";
        int ans = bfs(rev[a], rev[b]);
        pii c = make_pair(rev[a].Y, rev[a].X);
        pii d = make_pair(rev[b].Y, rev[b].X);
//        int ans = bfs(c, d);
//        assert(ans == bfs(rev[b], rev[a]));
        if (ans == -1) cout << "impossible" << endl;
        else cout << ans << endl;
    }


    return 0;
}


