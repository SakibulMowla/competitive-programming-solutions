#include "bits/stdc++.h"

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
const int inf = 1E9;
const ll mod = 1LL;

int x[] = {0,0,-1,1};//4-way
int y[] = {-1,1,0,0};//4-way

#define SZ  110

string grid[SZ];
queue <int> Q;
int dist[SZ][SZ];
bool mark[200];

int BFS (int n) {
    if (!mark[ grid[0][0] ]) return inf;

    while (!Q.empty()) Q.pop();
    Q.push(0);  Q.push(0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = inf;
    dist[0][0] = 1;

    while(!Q.empty()) {
        int a = Q.front();  Q.pop();
        int b = Q.front();  Q.pop();
        for (int i = 0; i < 4; i++) {
            int u = a + x[i];
            int v = b + y[i];
            if (u>=0 && v>=0 && u<n && v<n && mark[grid[u][v]] && dist[u][v] > dist[a][b] + 1) {
                dist[u][v] = dist[a][b] + 1;
                Q.push(u);  Q.push(v);
            }
        }
    }

    return dist[n-1][n-1];
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> grid[i];

        int ans = inf;
        for (int mask = 0; mask < 1024; mask++) {
            mem(mark, 0);
            for (int i = 0; i < 10; i++)
                if (mask & (1<<i)) mark['a'+i] = 1;
                else mark['A'+i] = 1;
            ans = min(ans, BFS(n));
        }

        if (ans >= inf) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}







