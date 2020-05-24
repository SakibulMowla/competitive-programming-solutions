#include "bits/stdc++.h"

using namespace std;

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

#define SZ  5010

char arr[2500010];
vector <int> adj[SZ];
int a[SZ];
bool col[SZ];

int solve (int u) {
    if (col[u]) return 0;
    col[u] = 1;
    int ret = 1;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        ret += solve(v);
    }
    return ret;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, k;
    char *s;

    while (scanf("%d %d", &n, &k) == 2) {
        for (int i = 0; i < k; i++) {
            scanf("%d", &a[i]);
        }

        sort(a, a+k);

        for (int i = 0; i <= n; i++) {
            clr(adj[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf(" %[^\n]", arr);
            s = strtok(arr, " ");
            int u = atoi(s);

            s = strtok(NULL, " ");
            while (s != NULL) {
                int v = atoi(s);
                adj[u].pb(v);
                s = strtok(NULL, " ");
            }
        }

//        now++;
        int ans = 0, node;

        for (int i = 0; i < k; i++) {
            mem(col, 0);
            int val = solve(a[i]);
            if (val > ans) {
                ans = val;
                node = a[i];
            }
        }

        printf("%d\n", node);
    }

    return 0;
}






