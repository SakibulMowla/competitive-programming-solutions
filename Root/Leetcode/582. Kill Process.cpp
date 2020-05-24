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


#define SZ 100010

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map <int, int> mp;
        map <int, int> rmp;
        int n = pid.size(), cnt = 0;
        vector < vector <int> > G(2 * n, vector <int> ());
        for (int i = 0; i < n; i++) {
            int v = pid[i], u = ppid[i];
            if (mp.find(u) == mp.end()) mp[u] = cnt, rmp[cnt] = u, cnt++;
            if (mp.find(v) == mp.end()) mp[v] = cnt, rmp[cnt] = v, cnt++;
            G[mp[u]].push_back(mp[v]);
        }
        vector <int> ans;
        if (mp.find(kill) != mp.end()) {
            kill = mp[kill];
            queue <int> Q;
            Q.push(kill);
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                ans.push_back(rmp[u]);
                for (auto v: G[u]) {
                    Q.push(v);
                }
            }
        }
        return ans;
    }
};

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    Solution sol;
    vector <int> A = {1, 3, 10, 5};
    vector <int> B = {3, 0, 5, 3};
    int k = 5;
    vector <int> ans = sol.killProcess(A, B, k);
    for (auto x: ans) cout << x << ' ';

    return 0;
}




