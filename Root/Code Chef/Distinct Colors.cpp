#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000007;

#define SZ 400010
#define SZ1 400010
#define SZ2 400010

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

int n, k;
vector <int> val;
vector <int> adj[SZ];
int col[SZ];
pii tym[SZ];

void dfs (int u, int p) {
    tym[u].X = sz(val);
    for (auto v: adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    val.pb(col[u]);
    tym[u].Y = sz(val) - 1;
    return;
}


struct data {
    int l, r, num;
    char c;
};

data arr[SZ+SZ1];
int tree[SZ2];
int M[100010];
int ans[SZ1];

bool comp(data p,data q) {
    if(p.r == q.r) return p.c < q.c;
    return p.r < q.r;
}

void build(int node,int b,int e) {
    tree[node] = 0;
    if(b == e) return;
    int mid = (b + e) >> 1;
    build(left);
    build(riht);
}

void update(int node,int b,int e,int x,int val) {
    if(b == e) {
        tree[node] = val;
        return;
    }
    int mid = (b + e) >> 1;
    if(x <= mid) update(left, x, val);
    else update(riht, x, val);
    tree[node] = tree[node<<1] + tree[(node<<1)|1];
}

int query(int node,int b,int e,int f,int t) {
    if(b >= f && e <= t)
        return tree[node];
    int mid = (b + e) >> 1, sum = 0;
    if(f <= mid) sum = query(left, f, t);
    if(t > mid) sum += query(riht, f, t);
    return sum;
}




int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

//    ios::sync_with_stdio(false);

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n - 1; i++) {
        int x;
        scanf("%d", &x);
        adj[i+2].pb(x);
        adj[x].pb(i+2);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &col[i]);
    }

    val.pb(0);
    dfs(1, -1);

    int i, j, q;

    q = n;

    for(i=0; i<n; i++) {
//        scanf("%d", &arr[i].l);
        arr[i].l = val[i+1];
        arr[i].r = i+1;
        arr[i].c = '1';
    }

    j = 0;

    for(i=n; i<n+q; i++) {
//        scanf("%d", &arr[i].l);
//        scanf("%d", &arr[i].r);
        arr[i].l = tym[i-n+1].X;
        arr[i].r = tym[i-n+1].Y;
        arr[i].c = '2';
        arr[i].num = j++;
    }

    sort(arr, arr+n+q, comp);
    memset(M, 0, sizeof(M));

    ll ans5 = 0;

    for(i=0; i<n+q; i++) {
        if(arr[i].c == '1') {
            if( !M[ arr[i].l ] ) {
                update(1, 1, n, arr[i].r, 1);
                M[ arr[i].l ] = arr[i].r;
            } else {
                update(1, 1, n, M[ arr[i].l ], 0);
                update(1, 1, n, arr[i].r, 1);
                M[ arr[i].l ] = arr[i].r;
            }
        } else {
            ans[arr[i].num] = query(1, 1, n, arr[i].l, arr[i].r);
            ans5 += (ll)(ans[arr[i].num]);
        }
    }

    printf("%lld\n", ans5);

    return 0;
}




