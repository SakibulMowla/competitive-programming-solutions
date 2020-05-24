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

#define SZ 100010

vector <int> adj[SZ];
int tmpCol[SZ];
int col[SZ];
int tym;
int strt[SZ];
int endd[SZ];

void Dfs (int u, int p) {
    strt[u] = ++tym;
    col[tym] = tmpCol[u];
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (v != p) {
            Dfs (v, u);
        }
    }
    endd[u] = tym;
}

struct data {
    int x, y, val, indx;
};
data arr[SZ];

int BLOCK;

bool comp (data p, data q) {
    if (p.x/BLOCK != q.x/BLOCK) {
        return p.x/BLOCK < q.x/BLOCK;
    }
    return p.y < q.y;
}

int cnt[SZ];
int ans[SZ];

void Add (int pos) {
    cnt[col[pos]]++;
    if (cnt[col[pos]] > 0) ans[cnt[col[pos]]]++;
}

void Remove (int pos) {
    if (cnt[col[pos]] > 0) ans[cnt[col[pos]]]--;
    cnt[col[pos]]--;
}

int FinalAns[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);

    BLOCK = sqrt(n) + 1;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmpCol[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    tym = -1;
    Dfs(1, -1);

    for(int i = 0; i < m; i++) {
        int a;
        scanf("%d %d", &a, &arr[i].val);
        arr[i].x = strt[a];
        arr[i].y = endd[a];
        arr[i].indx = i;
    }

    sort (arr, arr+m, comp);

    int curL = 0, curR = 0;
    for (int i = 0; i < m; i++) {
        int L = arr[i].x;
        int R = arr[i].y;

        while (curL < L) {
            Remove(curL);
            curL++;
        }
        while (curL > L) {
            Add(curL-1);
            curL--;
        }
        while (curR <= R) {
            Add(curR);
            curR++;
        }
        while (curR > R + 1) {
            Remove(curR-1);
            curR--;
        }
        FinalAns[ arr[i].indx ] = ans[ arr[i].val ];
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", FinalAns[i]);
    }

    return 0;
}






