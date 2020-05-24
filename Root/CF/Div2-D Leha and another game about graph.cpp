#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> degreeRequired(n + 1), degreeProvided(n + 1, 0);
    vector<vector<int>> G(n + 1, vector <int> ());
    vector<vector<int>> edgeNumber(n + 1, vector <int> ());

    int root = 1;
    for (int i = 1; i <= n; i++) {
        cin >> degreeRequired[i];
        if (degreeRequired[i] == -1) root = i;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        edgeNumber[u].push_back(i);
        edgeNumber[v].push_back(i);
    }

    vector<int> isVisited(n + 1, false);
    queue<int> Q;

    Q.push(root);
    isVisited[root] = true;

    stack<pair<int, int>> edges;
    stack<int> treeEdgeNumber;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (isVisited[v] == false) {
                isVisited[v] = true;
                Q.push(v);
                edges.push({u, v});
                treeEdgeNumber.push(edgeNumber[u][i]);
            }
        }
    }

    vector<int> ans;

    while (!edges.empty()) {
        pair<int, int> tmp = edges.top(); edges.pop();
        int no = treeEdgeNumber.top(); treeEdgeNumber.pop();
        if (degreeRequired[tmp.second] != -1 && degreeRequired[tmp.second] != degreeProvided[tmp.second]) {
            ans.push_back(no);
            degreeProvided[tmp.second] ^= 1;
            degreeProvided[tmp.first] ^= 1;
        }
    }

    if (degreeRequired[root] == -1 || degreeRequired[root] == degreeProvided[root]) {
        cout << ans.size() << endl;
        for(auto x: ans) cout << x << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}