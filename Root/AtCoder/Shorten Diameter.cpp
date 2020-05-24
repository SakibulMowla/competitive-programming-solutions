#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& G, int u, int p, int lev) {
    int ret = (lev < 0);
    for (int v: G[u]) {
        if (v != p) {
            ret += dfs(G, v, u, lev - 1);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> G(n, vector<int> ());
    vector<pair<int, int>> E;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u - 1].emplace_back(v - 1);
        G[v - 1].emplace_back(u - 1);
        E.push_back({u - 1, v - 1});
    }
    
    int ans = numeric_limits<int>::max();
    if (k & 1) {
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, dfs(G, E[i].first, E[i].second, k / 2) + dfs(G, E[i].second, E[i].first, k / 2));    
        }
    } else {
        for (int i = 0; i < n; i++) {
            ans = min(ans, dfs(G, i, -1, k / 2));
        }
    }
    cout << ans << endl;
    
    return 0;
}

