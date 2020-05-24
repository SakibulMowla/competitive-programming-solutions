class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>>& edges) {
        vector <int> deg(n, 0);
        vector < vector <int> > G(n, vector <int> ());
        for (auto x: edges) {
            deg[x.first]++;
            G[x.second].push_back(x.first);
        }
        queue <int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                cnt++;
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v: G[u]) {
                deg[v]--;
                if (deg[v] == 0) {
                    q.push(v);
                    cnt++;
                }
            }
        }
        return n == cnt;
    }
};