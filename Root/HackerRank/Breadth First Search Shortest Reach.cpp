#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

void bfs (int n, vector < vector <int> > &adj, int s) {
    queue <int> q;
    vector <int> dist(n, numeric_limits <int> :: max());
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v:adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    bool strt = false;
    for (int i = 0; i < n; i++) {
        if (i != s) {
            if (strt) cout << ' ';
            cout << (dist[i] == numeric_limits <int> :: max() ? -1: dist[i] * 6);
            if (!strt) strt = true;
        }
    }
    cout << endl;
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;
        vector < vector <int> > adj(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x-1].pb(y-1);
            adj[y-1].pb(x-1);
        }
        int s;
        cin >> s;
        bfs(n, adj, s - 1);
    }

    return 0;
}







