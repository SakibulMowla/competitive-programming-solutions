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

struct data {
    ll city, dist;
    data () {}
    data (ll a, ll b) {
        city = a, dist = b;
    }
    bool operator < (const data& p) const {
        return dist > p.dist;
    }
};

vector <data> adj[SZ];
int mark[SZ];
ll dist[SZ];
priority_queue <data> pq;

ll solve () {
    ll mn = -1;
    while (!pq.empty()) {
        data u = pq.top();
        pq.pop();
        if (!mark[u.city]) {
            if (mn == -1) mn = u.dist;
            else mn = min(mn, u.dist);
        }
        for (int i = 0; i < sz(adj[u.city]); i++) {
            data v = adj[u.city][i];
            if (dist[v.city] > u.dist + v.dist) {
                dist[v.city] = u.dist + v.dist;
                pq.push(data(v.city, dist[v.city]));
            }
        }
    }
    return mn;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(data(v, w));
        adj[v].pb(data(u, w));
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = 1E16;
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        mark[x] = 1;
        dist[x] = 0;
        pq.push(data(x, 0));
    }

    cout << solve() << endl;

    return 0;
}




