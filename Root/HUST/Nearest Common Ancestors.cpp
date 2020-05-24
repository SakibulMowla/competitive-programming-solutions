#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 10010

vector <int> adj[SZ], rev[SZ];
int lev[SZ];
int P[SZ][16];

int findRoot (int u) {
    if (rev[u].size()) return findRoot(rev[u][0]);
    else return u;
}

void dfs (int u) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        lev[v] = lev[u] + 1;
        P[v][0] = u;
        dfs(v);
    }
    return;
}

void process (int n) {
    int root = findRoot(n);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 14; j++) {
            P[i][j] = -1;
        }
    }

    lev[root] = 0;
    dfs(root);

    for (int j = 1; j <= 14; j++) {
        for (int i = 1; i <= n; i++) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }

    return;
}

int LCA (int u, int v) {
    if (lev[v] > lev[u]) swap(u, v);

    for (int i = 14; i >= 0; i--) {
        if (lev[u] - (1 << i) >= lev[v]) {
            u = P[u][i];
        }
    }

    if (u == v) return u;

    for (int i = 14; i >= 0; i--) {
        if (P[u][i] != -1 && P[v][i] != -1 && P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }

    return P[v][0];
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            rev[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            rev[v].push_back(u);
        }

        process(n);

        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }


    return 0;
}




