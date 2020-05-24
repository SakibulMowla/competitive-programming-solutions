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

#define SZ 3010

int g[SZ][SZ];
vector <int> adj[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
        adj[a].pb(b);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i != j) {
            int cnt = 0;
            for (int k = 0; k < sz(adj[i]); k++) {
                if (adj[i][k] != i && adj[i][k] != j && g[ adj[i][k] ][j]) {
                    cnt++;
                }
            }
            ans += cnt * (cnt-1) / 2;
        }
    }

    cout << ans << '\n';


    return 0;
}






