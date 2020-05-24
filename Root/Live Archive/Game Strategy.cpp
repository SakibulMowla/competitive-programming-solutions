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
const int inf = 1E7;
const ll mod = 1E9;

#define SZ 30

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector < vector <int> > adj(n);
        char s[SZ];

        for (int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);
            adj[i] = vector <int> (m);
            for (int j = 0; j < m; j++) {
                scanf("%s", &s);
                int mask = 0;
                for (int k = 0; s[k]; k++) {
                    mask |= (1 << (s[k] - 'a'));
                }
                adj[i][j] = mask;
            }
        }

        vector < vector <int> > dist(n, vector <int> (n, inf));

        for (int v = 0; v < n; v++) {
            dist[v][v] = 0;
            int mask = (1 << v);
            for (int d = 1; d <= n; d++) {
                int tmask = 0;
                for (int u = 0; u < n; u++) {
                    if (dist[u][v] == inf) {
                        for (int i = 0; i < sz(adj[u]); i++) {
                            if ((mask & adj[u][i]) == adj[u][i]) {
                                tmask |= (1 << u);
                                dist[u][v] = d;
                                break;
                            }
                        }
                    }
                }
                mask |= tmask;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf(j == n - 1? "%d\n": "%d ", dist[i][j] == inf ? -1 : dist[i][j]);
            }
        }
    }


    return 0;
}






