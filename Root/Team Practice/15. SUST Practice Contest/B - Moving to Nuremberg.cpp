#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

using namespace  std;

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

#define SZ 50000+10

vector <int> adj[SZ];
vector <ll> cost[SZ];
ll f[SZ];
queue <int> Q;
int par[SZ];
ll tot;
ll dist[SZ];
ll rootAns;

void BFS () {
    while (!Q.empty()) Q.pop();

    Q.push(1);
    Q.push(-1);

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int p = Q.front(); Q.pop();

        rootAns += f[u] * dist[u];

        int k = sz(adj[u]);
        for (int i = 0; i < k; i++) {
            int v = adj[u][i];
            if (v == p) continue;
            par[v] = u;
            dist[v] = dist[u] + cost[u][i];
            Q.push(v);
            Q.push(u);
        }
    }

    return;
}

ll ans[SZ], minim;

void BFS2 () {
    while (!Q.empty()) Q.pop();

    Q.push(1);
    Q.push(-1);

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int p = Q.front(); Q.pop();
        int k = sz(adj[u]);

        for (int i = 0; i < k; i++) {
            int v = adj[u][i];
            if (v == p) continue;

            ans[v] = ans[u] - (f[v] * cost[u][i]) + ( (tot-f[v]) * cost[u][i] );
            minim = min(minim, ans[v]);

            Q.push(v);
            Q.push(u);
        }
    }
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i <= n; i++) {
            clr(adj[i]);
            clr(cost[i]);
            par[i] = -1;
            f[i] = 0;
            dist[i] = 0;
        }

        tot = 0LL;
        rootAns = 0LL;

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            ll w;
            scanf("%d %d %I64d", &u, &v, &w);

            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }

        int m;
        scanf("%d", &m);

        for (int i = 0; i < m; i++) {
            int node;
            ll x;
            scanf("%d %I64d", &node, &x);
            f[node] = x;
            tot += x;
        }

        BFS();
        ans[1] = rootAns;
        minim = rootAns;

        for (int i = 1; i <= n; i++) {
            int j = i;
            while (par[j] != -1) {
                f[ par[j] ] += f[j];
                j = par[j];
            }
        }

        BFS2();

        bool blank = 0;

        printf("%I64d\n", minim*2LL);
        for (int i = 1; i <= n; i++) if (ans[i] == minim) {
            if (blank) printf(" ");
            else blank = 1;
            printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}






