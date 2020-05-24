#include <bits/stdc++.h>

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
const int inf = 1;
const ll mod = 1LL;

#define SZ 5010

pii arr[SZ][2];
vector <int> adj[SZ];

void dfs (int u, int p) {
    arr[u][0] = {u, 0};
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (v == p) continue;
        dfs(v, u);
        if (arr[v][0].Y + 1 > arr[u][0].Y) {
            arr[u][1] = arr[u][0];
            arr[u][0] = arr[v][0];
            arr[u][0].Y++;
            arr[u][0].X = v;
        } else if (arr[v][0].Y + 1 > arr[u][1].Y) {
            arr[u][1] = arr[v][0];
            arr[u][1].Y++;
            arr[u][1].X = v;
        }
    }
    return;
}

void solve (int u, int p) {
    if (p) {
        for (int i = 0; i < 2; i++) if (arr[p][i].X != u) {
            if (arr[p][i].Y + 1 > arr[u][0].Y) {
                arr[u][1] = arr[u][0];
                arr[u][0] = arr[p][i];
                arr[u][0].Y++;
                arr[u][0].X = p;
            } else if (arr[p][i].Y + 1 > arr[u][1].Y) {
                arr[u][1] = arr[p][i];
                arr[u][1].Y++;
                arr[u][1].X = p;
            }
        }
    }

    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (v == p) continue;
        solve(v, u);
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        for (int i = 0; i <= n; i++) {
            clr(adj[i]);
            arr[i][0] = arr[i][1] = {0, 0};
        }

        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int v;
                cin >> v;
                adj[i].pb(v);
            }
        }

        dfs(1, 0);
        solve(1, 0);

        int mn = n, mx = 0;
        for (int i = 1; i <= n; i++) {
            mn = min(mn, arr[i][0].Y);
            mx = max(mx, arr[i][0].Y);
        }

        cout << "Best Roots  :";
        for (int i = 1; i <= n; i++) {
            if (arr[i][0].Y == mn) {
                cout << ' ' << i;
            }
        }
        cout << endl;

        cout << "Worst Roots :";
        for (int i = 1; i <= n; i++) {
            if (arr[i][0].Y == mx) {
                cout << ' ' << i;
            }
        }
        cout << endl;
    }

    return 0;
}





