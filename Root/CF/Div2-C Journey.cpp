#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const ll mod = 1LL;

#define SZ  100010

vector <int> adj[SZ];

double dfs(int u, int p, int l) {
    int cnt = 0;
    double ret = 0;
    for (auto v: adj[u]) {
        if (v != p) {
            cnt++;
            ret += dfs(v, u, l + 1);
        }
    }
    if (cnt == 0) return l;
    return ret / (double)cnt;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cout << fixed << setprecision(12) << dfs(1, 1, 0) << endl;

    return 0;
}


