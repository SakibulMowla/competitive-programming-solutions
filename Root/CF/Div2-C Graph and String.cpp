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


#define SZ 510

int mat[SZ][SZ];
vector <int> adj[SZ];
char col[SZ];
bool vis[SZ];
int n;
bool flag;

void dfs (int u, int p, int ccl) {
    vis[u] = true;
    if (!ccl) col[u] = 'a';
    else col[u] = 'c';
    for (int i = 1; i <= n; i++) if (u != i) {
        if (mat[u][i] == 0 && (col[i] == col[u] || col[i] == 'b')) {
            flag = false;
            return;
        }
        if (col[i] == 0 && mat[u][i] == 0) {
            dfs(i, u, ccl^1);
        }
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(false);

    int m;
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i <= n; i++) {
            clr(adj[i]);
            col[i] = 0;
        }
        mem(mat, 0);
        mem(vis, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            mat[u][v] = mat[v][u] = 1;
//            adj[u].pb(v);
        }
        flag = true;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                if (mat[i][j] != mat[j][i]) {
//                    flag = false;
//                    goto HELL;
//                }
//            }
//        }
        if (m == 0) {
            if (n == 1) {
                printf("Yes\n");
                printf("a\n");
            } else if (n == 2) {
                printf("Yes\n");
                printf("ac\n");
            } else {
                printf("No\n");
            }
        } else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) if (j != i) {
                    for (int k = 1; k <= n; k++) if (k != i && k != j) {
                        if (mat[i][j] == 1 && mat[i][k] == 1 && mat[j][k] == 0) {
                            if (col[i] == 0 || col[i] == 'b') {
                                if (col[j] == 0 && col[k] == 0) {
                                    col[i] = 'b';
                                    col[j] = 'a';
                                    col[k] = 'c';
                                } else if (col[j] != 0 && col[k] != 0) {
                                    if (col[j] == 'b' || col[k] == 'b' || col[j] == col[k]) {
                                        flag = false;
                                        goto HELL;
                                    }
                                    col[i] = 'b';
                                } else if (col[j] != 0) {
                                    if (col[j] == 'b') {
                                        flag = false;
                                        goto HELL;
                                    }
                                    col[i] = 'b';
                                    if (col[j] == 'a') col[k] = 'c';
                                    else col[k] = 'a';
                                } else if (col[k] != 0) {
                                    if (col[k] == 'b') {
                                        flag = false;
                                        goto HELL;
                                    }
                                    col[i] = 'b';
                                    if (col[k] == 'a') col[j] = 'c';
                                    else col[j] = 'a';
                                }
                            } else {
                                flag = false;
                                goto HELL;
                            }
                        }
                    }
                }
            }

            for (int i = 1; i <= n; i++) {
                if (!vis[i] && col[i] != 'b') {
                    int now = 0;
                    if (col[i] == 'c') now = 1;
                    dfs(i, -1, now);
                }
            }

            HELL:;
            if (!flag) {
                printf("No\n");
            } else {
                printf("Yes\n");
                for (int i = 1; i <= n; i++) {
                    printf("%c", col[i]);
                }
                printf("\n");
            }
        }
    }


    return 0;
}





