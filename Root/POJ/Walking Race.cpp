#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 1000010

pii dist[SZ][2]; ///node, length
int fst[2*SZ], nxt[2*SZ], vv[2*SZ], cost[2*SZ], e;

void init () {
    memset(fst, -1, sizeof fst);
    e = 0;
}

void add (int u, int v, int c) {
    vv[e] = v, nxt[e] = fst[u], cost[e] = c, fst[u] = e++;
}

void dfs (int u, int p) {
    dist[u][0] = dist[u][1] = {u, 0};
    for (int i = fst[u]; i != -1; i = nxt[i]) {
        int v = vv[i], w = cost[i];
        if (v != p) {
            dfs(v, u);
            if (dist[u][0].Y < w + dist[v][0].Y) {
                dist[u][1] = dist[u][0];
                dist[u][0].Y = w + dist[v][0].Y;
                dist[u][0].X = v;
            } else if (dist[u][1].Y < w + dist[v][0].Y) {
                dist[u][1].Y = w + dist[v][0].Y;
                dist[u][1].X = v;
            }
        }
    }
    return;
}

void solve (int u, int p, int last) {
    if (p) {
        for (int i = 0; i < 2; i++) if (dist[p][i].X != u) {
            if (dist[u][0].Y < last + dist[p][i].Y) {
                dist[u][1] = dist[u][0];
                dist[u][0].Y = last + dist[p][i].Y;
                dist[u][0].X = p;
            } else if (dist[u][1].Y < last + dist[p][i].Y) {
                dist[u][1].Y = last + dist[p][i].Y;
                dist[u][1].X = p;
            }
        }
    }
    for (int i = fst[u]; i != -1; i = nxt[i]) {
        int v = vv[i], w = cost[i];
        if (v != p) {
            solve(v, u, w);
        }
    }
    return;
}

pii mn[SZ], mx[SZ];

int Sliding_window (int n, int m) {
//    printf("here\n");
    int ans = 0;
    int l1 = 0, r1 = 0, l2 = 0, r2 = 0;

    for (int lft = 1, riht = 1; riht <= n; riht++) {
//        printf("lft = %d riht = %d\n", lft, riht);
        int now = dist[riht][0].Y;

        while ((r1-l1) && mn[r1-1].X >= now) {
            r1--;
        }
        mn[r1++] = {now, riht};

        while ((r2-l2) && mx[r2-1].X <= now) {
            r2--;
        }
        mx[r2++] = {now, riht};

        if (mx[l2].X - mn[l1].X <= m) {
            ans = max(ans, riht - lft + 1);
        } else {
            while (mx[l2].X - mn[l1].X > m) {
                lft++;
                if (mx[l2].Y < lft) l2++;
                if (mn[l1].Y < lft) l1++;
            }
        }
    }

    return ans;
}

int main () {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);

    init();

    for (int i = 1; i <= n - 1; i++) {
        int f, d;
        scanf("%d %d", &f, &d);
        add(i+1, f, d);
        add(f, i+1, d);
    }

//    printf("Before\n");
    dfs(1, 0);
//    printf("dfs end\n");
    solve(1, 0, 0);
//    printf("solve end\n");

    printf("%d\n", Sliding_window(n, m));

    return 0;
}







