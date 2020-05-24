#include "bits/stdc++.h"

using namespace std;

#define mem(a, b) memset(a, b, sizeof a)
#define sz(a) (int)a.size()
#define pb push_back

#define SZ 5050

int vis[SZ];
int supply[SZ];
int ar1[SZ], ar2[SZ];
vector <int> adj[SZ];
bool haveTo[SZ];
int col[SZ];
int thik_ache;

int dfs(int u) {
    col[u] = 1;
    if (vis[u]) return supply[u];
    int ret = -1;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (col[v]) continue;
        ret = dfs(v);
        if (ret != -1) return ret;
    }
    return ret;
}

void dfs2 (int u, int cost) {
    col[u] = 2;
    if (vis[u] && supply[u] != cost) {
        thik_ache = 0;
        return;
    }
    supply[u] = cost;
    vis[u] = 1;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (col[v] == 2) continue;
        if (vis[v] && supply[u] != supply[v]) {
            thik_ache = 0;
            return;
        }
        dfs2(v, cost);
    }
    return;
}

bool ok (int a, int b, int mn, int mx) {
    return ((supply[b]-supply[a]) >= mn && (supply[b]-supply[a]) <= mx);
}

int now = 0;

int main () {
//    freopen("1.txt", "r", stdin);
//    freopen("4.txt", "w", stdout);

    int j, l, w, mn, mx;
    int cs = 0;

    while (cin >> j >> l >> w >> mn >> mx && (j+l+w+mn+mx)) {
        cs++;
        if (cs == 17 && now) {
            cout << j << ' ' << l <<' '<< w << ' ' << mn << ' ' << mx << '\n';
        }
        mem(vis, 0);
        mem(supply, 0);
        int reduce = 0;

        for (int i = 0; i < l; i++) {
            int a, b;
            cin >> a >> b;
            if (cs == 17 && now) {
                cout << a << ' ' << b << '\n';
            }

            ar1[i] = a;
            ar2[i] = b;

            if (!vis[a] && !vis[b]) {
                supply[a] = 0;
                supply[b] = mn;
            } else if (!vis[a] && vis[b]) {
                supply[a] = supply[b] - mn;
            } else if (vis[a] && !vis[b]) {
                supply[b] = supply[a] + mn;
            }

            vis[a] = vis[b] = 1;
            reduce = min(reduce, min(supply[a], supply[b]));
        }

        for (int i = 0; i <= j; i++) if (vis[i]) {
            supply[i] -= reduce;
        }

        int flag = 1;
        for (int i = 0; i < l; i++) {
            printf("i = %d %d %d\n", i, supply[ar1[i]], supply[ar2[i]]);
            if (!ok(ar1[i], ar2[i], mn, mx)) {
                flag = 0;
                break;
            }
        }

        for (int i = 0; i < 5001; i++)
            adj[i].clear();

        mem(haveTo, 0);
        mem(col, 0);

        for (int i = 0; i < w; i++) {
            int a, b;
            cin >> a >> b;
            if (cs == 17 && now) {
                cout << a << ' ' <<  b << '\n';
            }
            adj[a].pb(b);
            adj[b].pb(a);
            haveTo[a] = haveTo[b] = 1;
        }

        if (!flag) {
            cout << "1 Impossible\n" ;
            continue;
        }

        for (int i = 0; i <= j; i++) if (haveTo[i] && !col[i]) {
            thik_ache = 1;
            int tmp = dfs(i);
            if (tmp == -1) continue;
            dfs2(i, tmp);
            if (!thik_ache) {
                flag = 0;
                break;
            }
        }

        if (!flag) {
            cout << "2 Impossible\n" ;
            continue;
        }

        int ans = 0;
        for (int i = 0; i <= j; i++)
            ans = max(ans, supply[i]);

        cout << ans << '\n';
    }

    return 0;
}

/**
2 1 0 3 5
1 2

3 2 0 3 5
1 2
3 2

3 2 0 3 5
3 2
1 3

3 1 1 3 5
1 2
2 3

3 1 2 3 5
1 2
2 3
3 1

3 3 0 3 5
1 2
2 3
1 3

3 3 0 3 6
1 2
2 3
1 3

4 2 2 2 7
1 2
3 4
3 1
2 4

4 2 2 2 7
1 2
3 4
3 2
1 4

8 7 0 3 4
1 4
6 2
3 8
2 1
5 4
8 7
5 3

ans = 14

0 0 0 0 0
*/
