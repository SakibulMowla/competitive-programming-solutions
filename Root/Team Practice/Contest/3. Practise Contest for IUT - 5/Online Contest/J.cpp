#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <map>
using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;

int t, n, m;
VI x, in[2], st[2][2];
VVI v;

int dfs (int a) {
    if (st[a][a].empty())  return n;
    int ret = 0, curr = a;
    while (!st[a][curr].empty()) {
        int u = st[a][curr].back();
        st[a][curr].pop_back();
        for (int i = 0; i < sz(v[u]); ++i) {
            in[a][v[u][i]]--;
            if (in[a][v[u][i]] == 0) {
                st[a][x[v[u][i]]].push_back(v[u][i]);
            }
        }
        if (st[a][curr].empty()) {
            curr ^= 1;
            ret++;
        }
    }
    return ret - 1;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        cin >> n >> m;

        x = VI(n), in[0] = VI(n, 0), in[1] = VI(n, 0);
        v = VVI(n);

        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            --x[i];
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            v[a-1].pb(b-1);
            in[0][b-1]++;
            in[1][b-1]++;
        }
        st[0][0].clear();
        st[0][1].clear();
        st[1][0].clear();
        st[1][1].clear();
        for (int i = 0; i < n; ++i) {
            if (in[0][i] == 0) {
                st[0][x[i]].pb(i);
                st[1][x[i]].pb(i);
            }
        }
        cout << min(dfs(0), dfs(1)) << '\n';
    }
    return 0;
}
