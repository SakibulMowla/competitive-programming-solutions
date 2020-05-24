#include <iostream>
#include <vector>
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


#define SZ 1010

int capital[SZ], col[SZ];
vector <int> adj[SZ], group[SZ];
int mat[SZ][SZ];

void dfs (int u, int lead) {
    group[lead].pb(u);
    col[u] = 1;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (!col[v]) {
            dfs(v, lead);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        capital[x] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        mat[u][v] = mat[v][u] = 1;
    }

    int cnt = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        if (capital[i] == 1) {
            dfs(i, i);
            mx = max(mx, sz(group[i]));
            for (int j = 0; j < sz(group[i]); j++) {
                for (int k = j + 1; k < sz(group[i]); k++) {
                    if (mat[group[i][j]][group[i][k]] == 0) {
                        mat[group[i][j]][group[i][k]] = mat[group[i][k]][group[i][j]] = 1;
                        cnt++;
                    }
                }
            }
        }
    }

    vector <int> store;
    for (int i = 1; i <= n; i++) {
        if (!col[i]) {
            store.pb(i);
        }
    }

    for (int j = 0; j < sz(store); j++) {
        for (int k = j + 1; k < sz(store); k++) {
            if (mat[store[j]][store[k]] == 0) {
                mat[store[j]][store[k]] = mat[store[k]][store[j]] = 1;
                cnt++;
            }
        }
    }

    cnt += sz(store) * mx;

    cout << cnt << endl;

    return 0;
}





