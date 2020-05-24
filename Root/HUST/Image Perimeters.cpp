#include <iostream>

using namespace  std;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

#define SZ 22

int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int xx[] = {-1, 1, 0, 0};
int yy[] = {0, 0, -1, 1};

char grid[SZ][SZ];
bool vis[SZ][SZ];

int dfs (int &r, int &c, int n, int m) {
    vis[n][m] = true;
    if (grid[n][m] == '.') return 0;

    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int u = n + xx[i];
        int v = m + yy[i];
        if (grid[u][v] == '.') {
            ret++;
        }
    }

    for (int i = 0; i < 8; i++) {
        int u = n + x[i];
        int v = m + y[i];
        if (u >= 1 && u <= r && v >= 1 && v <= c && !vis[u][v]) {
            ret += dfs(r, c, u, v);
        }
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int r, c, n, m;
    while (cin >> r >> c >> n >> m && (r + c + n + m)) {
        for (int i = 0; i <= 21; i++) {
            for (int j = 0; j <= 21; j++) {
                grid[i][j] = '.';
                vis[i][j] = false;
            }
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> grid[i][j];
            }
        }

        cout << dfs(r, c, n, m) << endl;
    }


    return 0;
}







