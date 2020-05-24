#include "bits/stdc++.h"

using namespace std;

#define SZ 100010
#define SZ1 20

#define sz(a) (int)a.size()

int n, par[SZ][SZ1], dist[SZ][SZ1], lev[SZ], col[SZ];
vector <int> adj[SZ];
int cnt[SZ];

int dfs(int u) {
    col[u] = 1;
    cnt[u] = 0;
    for(int i=0; i<sz(adj[u]); i++) {
        int j = adj[u][i];
        if(!col[j]) {
            lev[j] = lev[u] + 1;
            par[j][0] = u;
            dist[j][0] = 1;
            cnt[u] += dfs(j);
        }
    }
    return cnt[u] + 1;
}

void process() {
    int i, j , h, l;
    for(h=1; (1<<h)<=n; h++);
    --h;

    for(i=0; i<=n; i++)
        for(j=0; j<=h; j++)
            par[i][j] = -1, dist[i][j] = 0;

    lev[1] = 0;
    dfs(1);

    for(l=1; l<=h; l++)
        for(i=1; i<=n; i++)
            if(par[i][l-1] != -1) {
                dist[i][l] = dist[i][l-1] + dist[ par[i][l-1] ][l-1];
                par[i][l] = par[ par[i][l-1] ][l-1];
            }
}

int path, ancs;

void query(int p,int q) {
    path = 0;

    if(lev[p] < lev[q]) swap(p, q);
    int i, h;
    for(h=1; (1<<h)<=lev[p]; h++);
    --h;

    for(i=h; i>=0; i--) {
        if(lev[p] - (1<<i) >= lev[q]) {
            path += dist[p][i];
            p = par[p][i];
        }
    }
    if(p == q) {
        ancs = p;
        return;
    }
    for(i=h; i>=0; i--) {
        if(par[p][i] != -1 && par[q][i] != -1 && par[p][i] != par[q][i]) {
            path += dist[p][i];
            path += dist[q][i];
            p = par[p][i];
            q = par[q][i];
        }
    }
    ancs = par[p][0];
    path += 2;
    return;
}

int ancs_dist(int p, int q) {
    int i, h, cost=0;
    for(h=1; (1<<h)<=lev[p]; h++);
    --h;
    for(i=h; i>=0; i--) {
        if(lev[p]-(1<<i) >= lev[q]) {
            cost += dist[p][i];
            p = par[p][i];
        }
    }
    return cost;
}

int down[SZ];

int stone_throw(int node,int _throw) {
    int m = node;
    int i, h;
    for(h=1; (1<<h)<=lev[node]; h++);
    --h;
    for(i=h; i>=0; i--) {
        if(_throw - (1<<i) > 0) {
            node = par[node][i];
            _throw -= (1<<i);
        }
    }
    if (_throw == 1) {
        down[m] = node;
        node = par[node][0];
    }
    return node;
}

int main() {
    while(scanf("%d",&n) == 1) {
        for(int i=0; i<=n; i++) {
            adj[i].clear();
            col[i] = 0;
            cnt[i] = 0;
        }

        for(int i=0; i<n-1; i++) {
            int j, k;
            scanf("%d %d", &j, &k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }

        process();

        int m;
        scanf("%d", &m);

        while(m--) {
            int a, b;
            scanf("%d %d", &a, &b);
            query(a, b);
            if (a == b) printf("%d\n", n);
            else if (path%2 == 1) printf("0\n");
            else {
                down[a] = down[b] = 0;
                int p = ancs_dist(a, ancs);
                int q = ancs_dist(b, ancs);
                int p1 = p;
                int q1 = q;

                path /= 2;

                if(p >= path) p = stone_throw(a, path);
                else p = stone_throw(b, path);
                if(q >= path) q = stone_throw(b, path);
                else q = stone_throw(a, path);

                int ans = 0;
                int f = 0;

                if (down[a] > 0 && p1 >= path) ans += cnt[down[a]] + 1, f++;
                if (down[b] > 0 && q1 >= path) ans += cnt[down[b]] + 1, f++;
                if (f < 2) ans += n - 1 - cnt[p];

                ans = n - ans;

                printf("%d\n", ans);
            }
        }
    }

    return 0;
}

