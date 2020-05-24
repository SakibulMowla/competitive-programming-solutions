#include "bits/stdc++.h"

using namespace std;

#define SZ 100010

vector <int> adj[SZ];

double val[SZ];
double store[SZ];
double cost[SZ];
int deg[SZ];
int root;

double initialize (int node, int par) {
    store[node] = val[node];
    double denom = adj[node].size() - (par != 0);
    for (int i = 0; i < adj[node].size(); i++) {
        if (adj[node][i] == par) continue;
        store[node] += initialize(adj[node][i], node) / denom;
    }
    return store[node];
}

void solve (int node, int par) {
    double denom = adj[node].size() - (par != 0);
    cost[node] = store[node] - val[node];
    cost[node] *= denom;
    cost[node] /= (double)(adj[node].size());
    cost[node] += val[node];
    if (par != 0) {
        double tmp = cost[par] - val[par] - (store[node] / (double)adj[par].size());
        tmp *= (double)adj[par].size();
        tmp /= (double)(adj[par].size() - (par != root));
        tmp += val[par];
        cost[node] += tmp / (double)(adj[node].size());
    }
    for (int i = 0; i < adj[node].size(); i++) {
        if (adj[node][i] == par) continue;
        solve(adj[node][i], node);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            root = i;
        }
    }

    initialize(root, 0);
    solve(root, 0);

    int ans = 1;
    double mn = cost[1];

    for (int i = 1; i <= n; i++) {
        if (cost[i] < mn) {
            mn = cost[i];
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}
