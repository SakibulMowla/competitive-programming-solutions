#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.End())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  510

struct data {
    int to, strt, End, tym;
    data () {}
    data (int a, int b, int c, int d) {
        to = a, strt = b, End = c, tym = d;
    }
};

vector <data> adj[SZ];
int dist[SZ][500];
queue <int> Q;

void dijkstra (int n) {
    while (!Q.empty()) Q.pop();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 481; j++)
            dist[i][j] = inf;

    Q.push(0); Q.push(480);
    dist[0][480] = 720;

    while (!Q.empty()) {
        int u = Q.front();  Q.pop();
        int charge = Q.front();  Q.pop();
        // cout << "> " << u << ' ' << charge << Endl;

        for (int i = 0; i < sz(adj[u]); i++) {
            int v = adj[u][i].to;
            int strt = adj[u][i].strt;
            int End = adj[u][i].End;
            int tym = adj[u][i].tym;
            int cur = dist[u][charge] % 1440;

            if (tym > 240)  continue;

            int extra = max(0, strt - cur);
            if (min(480, charge + extra) >= 2 * tym) {
                if (dist[v][min(480, charge + extra) - 2 * tym] > dist[u][charge] + max(0, strt - cur) + tym) {
                    dist[v][min(480, charge + extra) - 2 * tym] = dist[u][charge] + max(0, strt - cur) + tym;
                    Q.push(v);
                    Q.push(min(480, charge + extra) - 2 * tym);
                }
            } else {
                int mtime = 2 * tym - charge;
                if (cur + mtime <= End) {
                    if (dist[v][charge + mtime - 2 * tym] > dist[u][charge] + mtime + tym) {
                        dist[v][charge + extra - 2 * tym] = dist[u][charge] + mtime + tym;
                        Q.push(v);
                        Q.push(charge + mtime - 2 * tym);
                    }
                } else {
                    mtime = strt + 1440 - cur;
                    if (dist[v][min(480, charge + mtime) - 2 * tym] > dist[u][charge] + mtime + tym) {
                        dist[v][min(480, charge + mtime) - 2 * tym] = dist[u][charge] + mtime + tym;
                        Q.push(v);
                        Q.push(min(480, charge + mtime) - 2 * tym);
                    }
                }
            }
        }
    }

    return;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int n, m;
    while (cin >> n >> m && (n+m)) {
        for (int i = 0; i < n; i++) {
            clr(adj[i]);
        }

        for (int i = 0; i < m; i++) {
            int u, v, strt, End, tym;
            cin >> u >> v;
            while(cin >> strt >> End >> tym) {
                adj[u].pb(data(v, strt, End, tym));
                adj[v].pb(data(u, strt, End, tym));
                if (End == 1439) break;
            }
        }

        dijkstra(n);

        int ans = 2E9;
        for (int i = 0; i <= 480; i++)
            ans = min(ans, dist[n-1][i]);

        cout << ans - 720 << '\n';
    }

    return 0;
}
