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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ 2002

struct data {
    int v;
    ll w;
    data () {}
    data (int b, ll c) {
        v = b, w = c;
    }
};

vector <data> adj[SZ];
ll mat[SZ][SZ];

void bfs (int s) {
    queue <int> q;
    bool vis[SZ];
    memset(vis, false, sizeof vis);
    q.push(s);
    vis[s] = true;
    mat[s][s] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < sz(adj[u]); i++) {
            int v = adj[u][i].v;
            if (!vis[v]) {
                vis[v] = true;
                mat[s][v] = mat[s][u] + adj[u][i].w;
                q.push(v);
            }
        }
    }

    return;
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
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].pb(data(b, c));
        adj[b].pb(data(a, c));
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout << mat[i][j] << ' ';
//        }
//        cout << endl;
//    }

    ll ans = 0;
    for (int i = 2; i <= n - 1; i++) {
        ll tmp = 0;
        for (int j = i + 1; j <= n; j++) {
            tmp += mat[i][j];
        }
        ans += min(mat[i][1], min(tmp, mat[1][i]));
    }
    ans += min(mat[n][1], mat[1][n]);

    cout << ans << endl;

    return 0;
}



