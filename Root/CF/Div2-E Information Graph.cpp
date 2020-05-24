#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;



#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())


#define SZ  100010

struct data {
    int type, x, y;
};

data cmnd[SZ];

vector <int> adj[SZ];
int in[SZ], out[SZ], deg[SZ], timer;

void dfs(int u, int par) {
    in[u] = ++timer;

    int i, j, k = sz(adj[u]);

    for(i = 0; i < k; i++) {
        j = adj[u][i];
        if(j == par || in[j]) continue;
        dfs(j, u);
    }

    out[u] = ++timer;
    return;
}

bool is_parent(int u, int v) {
    return ( (in[u] <= in[v]) && (out[v] <= out[u]) );
}

int par[SZ];

int find(int r) {
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void Union(int x, int y) {
    par[ find(x) ] = find(y);
    return;
}

int QueryToNumber[SZ];
vector <int> Question[SZ];
int ans[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, j, k, l, n, m, root, leaf, cnt;

    while(scanf("%d %d", &n, &m) == 2) {
        timer = 0;
        cnt = 0;
        for(i = 0; i <= max(n, m); i++) {
            adj[i].clear();
            in[i] = 0;
            out[i] = 0;
            deg[i] = 0;
            par[i] = i;
            ans[i] = 0;
            Question[i].clear();
        }

        for(i = 1; i <= m; i++) {
            scanf("%d", &cmnd[i].type);
            if(cmnd[i].type == 2)
                scanf("%d", &cmnd[i].x);
            else
                scanf("%d %d", &cmnd[i].x, &cmnd[i].y);

            if(cmnd[i].type == 1) {
                adj[ cmnd[i].y ].pb(cmnd[i].x);
                deg[ cmnd[i].x ]++;
            }
            else if(cmnd[i].type == 2) {
                QueryToNumber[i] = ++cnt;
            }
            else {
                Question[ cmnd[i].y ].pb(i);
            }
        }

        for(i = 1; i <= n; i++) {
            if(in[i] == 0 && deg[i] == 0)
                dfs(i, -1);
        }

        for(i = 1; i <= m; i++) {
            if(cmnd[i].type == 1) {
                Union(cmnd[i].x, cmnd[i].y);
            }
            else if(cmnd[i].type == 2) {
                l = QueryToNumber[i];
                k = sz(Question[l]);
                leaf = cmnd[i].x;

                for(j = 0; j < k; j++) {
                    root = cmnd[ Question[l][j] ].x;
                    ans[ Question[l][j] ] = ( (find(root) == find(leaf)) && is_parent(root, leaf) );
                }
            }
        }

        for(i = 1; i <= m; i++)
            if(cmnd[i].type == 3)
                printf("%s\n", ans[i] ? "YES" : "NO");
    }


    return 0;
}









