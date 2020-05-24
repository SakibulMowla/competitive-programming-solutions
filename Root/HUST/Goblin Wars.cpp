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

#define SZ 510

int xx[] = {-1, 1, 0, 0};
int yy[] = {0, 0, -1, 1};

void bfs (int &r, int &c, vector < vector <char> > &grid, queue <int> &Q, vector < vector <bool> > &flag, vector < vector <int> > &dist) {
    vector < vector <char> > ans = grid;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        int y = Q.front(); Q.pop();
        for (int k = 0; k < 4; k++) {
            int u = x + xx[k];
            int v = y + yy[k];
            if (u >= 0 && v >= 0 && u < r && v < c && grid[u][v] == '.' && flag[u][v] && flag[x][y]) {
                if (dist[u][v] > dist[x][y] + 1) {
                    dist[u][v] = dist[x][y] + 1;
                    ans[u][v] = ans[x][y];
                    Q.push(u);
                    Q.push(v);
                } else if (dist[u][v] == dist[x][y] + 1) {
                    if (ans[u][v] != ans[x][y]) {
                        ans[u][v] = '*';
                        flag[u][v] = false;
                    }
                }
            }
        }
    }
    grid = ans;
    return;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("3.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int r, c;
        cin >> r >> c;

        vector < vector <char> > grid(r, vector <char> (c));
        vector < vector <bool> > flag(r, vector <bool> (c, true));
        vector < vector <int> > dist(r, vector <int> (c, numeric_limits <int> :: max()));
        queue <int> Q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    Q.push(i);
                    Q.push(j);
                    dist[i][j] = 0;
                }
            }
        }

        bfs (r, c, grid, Q, flag, dist);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
