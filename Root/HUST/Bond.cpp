#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 50010
#define SZ1 100010

int par[SZ];
int rnk[SZ];

int P[SZ][20];
int dist[SZ][20];
int L[SZ];
int col[SZ];

struct data {
    int x, y, c;
    data() {}
    data (int _x, int _y, int _c) {
        x = _x, y = _y, c = _c;
    }
};

bool comp (data p, data q) {
    return p.c < q.c;
}

struct data1 {
    int v, c;
    data1 (int _v, int _c) {
        v = _v, c = _c;
    }
};

data a[SZ1];
vector <data1> adj[SZ];

void init (int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
        rnk[i] = 0;
        adj[i].clear();
        col[i] = 0;
    }
}

int Find (int r) {
    if (r == par[r]) return r;
    return par[r] = Find(par[r]);
}

void Union (int x, int y) {
    if (rnk[x] > rnk[y]) par[y] = x;
    else par[x] = y;
    if (rnk[x] == rnk[y]) rnk[y]++;
}


void MST (int n, int m) {
    sort(a, a + m, comp);
    for (int i = 0; i < m; i++) {
        int x = Find(a[i].x);
        int y = Find(a[i].y);
        if (x != y) {
            Union(x, y);
            adj[a[i].x].pb(data1(a[i].y, a[i].c));
            adj[a[i].y].pb(data1(a[i].x, a[i].c));
        }
    }
    return;
}

void dfs (int u) {
    col[u] = 1;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i].v;
        int c = adj[u][i].c;
        if (!col[v]) {
            L[v] = L[u] + 1;
            P[v][0] = u;
            dist[v][0] = c;
            dfs(v);
        }
    }
    return;
}

void process (int n) {
    int h;
    for (h = 1; (1<<h) <= n; h++);
    --h;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= h; j++) {
            P[i][j] = -1;
            dist[i][j] = 0;
        }
    }

    L[1] = 0;
    dfs(1);

    for (int lev = 1; lev <= h; lev++) {
        for (int i = 1; i <= n; i++) {
            if (P[i][lev-1] != -1) {
                dist[i][lev] = max(dist[i][lev-1], dist[ P[i][lev-1] ][lev-1]);
                P[i][lev] = P[ P[i][lev-1] ][lev-1];
            }
        }
    }

    return;
}

int query (int p, int q) {
//    printf(">> %d %d\n", L[p], L[q]);

    if (L[p] < L[q]) swap(p, q);

    int h;
    for (h = 1; (1<<h) <= L[p]; h++);
    --h;

//    printf(">>>>>h = %d\n", h);

    int mx = 0;

    for (int i = h; i >= 0; i--) {
        if (L[p] - (1<<i) >= L[q]) {
            mx = max(mx, dist[p][i]);
//            printf(">>> i = %d mx = %d\n", i, mx);
            p = P[p][i];
        }
    }

    if (p == q) return mx;

//    printf("Here\n");

    for (int i = h; i >= 0; i--) {
        if (P[p][i] != -1 && P[q][i] != -1 && P[p][i] != P[q][i]) {
            mx = max(mx, max(dist[p][i], dist[q][i]));
            p = P[p][i];
            q = P[q][i];
        }
    }

    return max(mx, max(dist[p][0], dist[q][0]));
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    bool blank = false;

    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        init(n);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].c);
        }

        MST(n, m);
        process(n);

        if (blank) printf("\n");
        else blank = true;

        int q;
        scanf("%d", &q);

        while (q--) {
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%d\n", query(u, v));
        }
    }


    return 0;
}







