#include <bits/stdc++.h>

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


#define SZ 3010

vector <int> adj[SZ];
vector <pii> order[SZ];
vector <pii> order2[SZ];
int dist[3010][3010];

void BFS (int now, int n) {
    vector <int> d(n + 1, -1);
    d[now] = 0;
    queue <int> Q;
    Q.push(now);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v: adj[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                Q.push(v);
                order[now].pb({v, d[v]});
                order2[v].pb({now, d[v]});
                dist[now][v] = d[v];
            }
        }
    }

    return;
}

int best;
vector <int> ans;

bool comp (pii a, pii b) {
    return a.Y > b.Y;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    for (int i = 1; i <= n; i++) {
        BFS(i, n);
    }

    for (int i = 1; i <= n; i++) {
        sort(order2[i].begin(), order2[i].end(), comp);
    }

    best = -1;
    ans.pb(0);
    ans.pb(0);
    ans.pb(0);
    ans.pb(0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                for (int k = 0, p = 0; k < sz(order2[i]) && p < 4; k++, p++) if (i != order2[i][k].X && j != order2[i][k].X) {
                    for (int l = sz(order[j]) - 1, q = 0; l >= 0 && q < 4; l--, q++) if (i != order[j][l].X && j != order[j][l].X) {
                        if (dist[i][j] > 0 && order[j][l].X != order2[i][k].X) {
                            if (best < order2[i][k].Y + order[j][l].Y + dist[i][j]) {
                                best = order2[i][k].Y + order[j][l].Y + dist[i][j];
                                ans[0] = order2[i][k].X;
                                ans[1] = i;
                                ans[2] = j;
                                ans[3] = order[j][l].X;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << endl;


    return 0;
}





