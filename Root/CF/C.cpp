//#include <bits/stdc++.h>

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

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010

vector<string> grid;

int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, -1, 1};

void dfs(int x, int y, int n, vector<vector<bool>>& col, vector<pii>& compo) {
    col[x][y] = true;
    compo.pb({x, y});
    for (int k = 0; k < 4; k++) {
        int nx = x + X[k];
        int ny = y + Y[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && grid[nx][ny] == '0' && !col[nx][ny]) {
            dfs(nx, ny, n, col, compo);
        }
    }
    return;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    pii start, target;
    cin >> start.X >> start.Y;
    cin >> target.X >> target.Y;

    grid = vector<string> (n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = "Z" + grid[i];
    }

    vector<vector<bool>> col(n + 1, vector<bool> (n + 1, false));
    vector<pii> compoA;
    dfs(start.X, start.Y, n, col, compoA);

    col = vector<vector<bool>>(n + 1, vector<bool> (n + 1, false));
    vector<pii> compoB;
    dfs(target.X, target.Y, n, col, compoB);

    int ans = 1E9;
    for (auto &p: compoA) {
        for (auto &q: compoB) {
            ans = min(ans, (p.X - q.X) * (p.X - q.X) + (p.Y - q.Y) * (p.Y - q.Y));
        }
    }

    cout << ans << endl;

    return 0;
}





