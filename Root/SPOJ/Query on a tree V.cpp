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

using namespace std;

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

struct CentroidTree {
    vector <vector <int>> adj;
    vector <vector <int>> lcapar;
    vector <int> ctpar, sub, level;
    vector <bool> IsDeleted;
    const int inf = 1E8;
    int n;
    int Root = 0;
    int LogN = 20;

    CentroidTree (int n): n(n), adj(n), ctpar(n), sub(n), level(n), IsDeleted(n, false) {
        LogN = 1 + ceil(log2(n));
        lcapar = vector <vector <int>>(n, vector <int>(LogN, -1));
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            inp(u);
            inp(v);
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        LCAPreprrocess();
        Decompose(Root, -1);
    }

    /// LCA Part Starts
    void LCADFS (int u, int p) {
        for (auto v: adj[u]) {
            if (v != p) {
                lcapar[v][0] = u;
                level[v] = level[u] + 1;
                LCADFS(v, u);
            }
        }
        return;
    }

    void LCAPreprrocess () {
        level[Root] = 0;
        lcapar[Root][0] = 0;
        LCADFS(Root, Root);
        for (int i = 1; i < LogN; i++) {
            for (int j = 0; j < n; j++) {
                if (lcapar[j][i-1] != -1) {
                    lcapar[j][i] = lcapar[lcapar[j][i-1]][i-1];
                }
            }
        }
        return;
    }

    int LCA (int a, int b) {
        if (level[a] > level[b]) swap(a, b);
        int d = level[b] - level[a];
        for (int i = 0; i < LogN; i++) {
            if (d&(1<<i)) {
                b = lcapar[b][i];
            }
        }
        if (a == b) return a;

        for (int i = LogN - 1; i >= 0; i--) {
            if (lcapar[a][i] != lcapar[b][i]) {
                a = lcapar[a][i];
                b = lcapar[b][i];
            }
        }
        return lcapar[a][0];
    }
    /// LCA Part Ends

    /// Centroid Decomposition Part Starts
    int SubTreeDFS (int u, int p) {
        sub[u] = 1;
        int ret = 1;
        for (auto v: adj[u]) {
            if (v != p && !IsDeleted[v]) {
                SubTreeDFS(v, u);
                sub[u] += sub[v];
                ret += sub[v];
            }
        }
        return ret;
    }

    int CentroidDFS (int u, int p, int &cnt) {
        for (auto v: adj[u]) {
            if (v != p && !IsDeleted[v] && sub[v] > cnt/2)
                return CentroidDFS(v, u, cnt);
        }
        return u;
    }

    void Decompose (int root, int p) {
        int cnt = SubTreeDFS(root, root);
        int centroid = CentroidDFS(root, root, cnt);
        ctpar[centroid] = p;
        IsDeleted[centroid] = true;

        for (auto v: adj[centroid]) {
            if (v != p && !IsDeleted[v]) {
                Decompose(v, centroid);
            }
        }

        return;
    }
    /// Centroid Decomposition Part Ends

    /// Particular Problem Part
    vector <multiset <int>> ans;
    vector <bool> col;

    int dist (int a, int b) {
        return level[a] + level[b] - 2 * level[LCA(a, b)];
    }

    void Update (int u) {
        int x = u;

        if (col[u]) { /// White
            while(x != -1) {
                ans[x].erase(ans[x].find(dist(x, u)));
                x = ctpar[x];
            }
        } else { /// Black
            while(x != -1) {
                ans[x].insert(dist(x, u));
                x = ctpar[x];
            }
        }

        col[u] = !col[u];

        return;
    }

    int Query (int u) {
        int x = u;
        int ret = inf;

        while (x != -1) {
            if (ans[x].size()) ret = min(ret, dist(x, u) + *ans[x].begin());
            x = ctpar[x];
        }

        return (ret == inf)? -1: ret;
    }

    int m;

    void Solve () {
        ans = vector <multiset <int>> (n);
        col = vector <bool> (n, false);

        inp(m);

        for (int i = 0; i < m ; i++) {
            int t, u;
            inp(t);
            inp(u);
            if (t == 0) {
                Update(u - 1);
            } else {
                printf("%d\n", Query(u - 1));
            }
        }

        return;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    CentroidTree CT(n);
    CT.Solve();

    return 0;
}

