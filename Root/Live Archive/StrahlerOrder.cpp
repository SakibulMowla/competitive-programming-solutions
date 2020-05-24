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

#define SZ  1010

vector <int> adj[SZ];
pii dp[SZ];
int in[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("3.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int k, m, p;
        cin >> k >> m >> p;

        for (int i = 0; i < 1000; i++) {
            clr(adj[i]);
            dp[i].X = 1;
            dp[i].Y = 0;
            in[i] = 0;
        }
        for (int i = 0; i < p; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].pb(v);
            in[v]++;
        }

        int True = 1;
        while (True) {
            True = 0;
            for (int i = 0; i < m; i++) {
                if (in[i] == 0) {
                    in[i] = -1;
                    True = 1;
                    if (dp[i].Y > 1) {
                        dp[i].Y = 1;
                        dp[i].X++;
                    }
//                    cout << "> " << i+1 << " " << dp[i].X << '\n';
                    for (int j = 0; j < sz(adj[i]); j++) {
                        int v = adj[i][j];
                        in[v]--;
                        if (dp[i].X > dp[v].X) {
                            dp[v].X = dp[i].X;
                            dp[v].Y = 1;
                        } else if (dp[i].X == dp[v].X) {
                            dp[v].Y++;
                        }
//                        cout << ">> " << v+1 << " " << dp[v].X << " " << " " << dp[v].Y << '\n';
                    }
                }
            }
        }

//        cout << k << " " << dfs(m-1).X << '\n';
        cout << k << " " << dp[m-1].X << '\n';
    }

    return 0;
}


/*

1 7 8
1 3
2 3
6 4
3 4
3 5
6 7
5 7
4 7

3 10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/

