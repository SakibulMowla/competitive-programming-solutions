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
#define SZ1 4*100010

int lazy[SZ1];
int tree[SZ1];

void push_down (int node) {
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
    tree[2*node] += lazy[node];
    tree[2*node+1] += lazy[node];
    lazy[node] = 0;
}

void Update (int node, int b, int e, int f, int t, int val) {
    if (f > t) return;
    if (b>=f && e<=t) {
        lazy[node] += val;
        tree[node] += val;
        return;
    }
    if (lazy[node]) push_down(node);
    int mid = (b+e)>>1;
    if (f <= mid) Update(2*node, b, mid, f, t, val);
    if (t > mid) Update(2*node+1, mid+1, e, f, t, val);
    return;
}

int Query (int node, int b, int e, int x) {
    if (b == e) return tree[node];
    if (lazy[node]) push_down(node);
    int mid = (b+e)>>1;
    if (x <= mid) return Query(2*node, b, mid, x);
    return Query(2*node+1, mid+1, e, x);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    vector <int> pos(n+1);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pos[x] = i + 1;
    }

    int now;
    int strt = 0;
    int endd = n+1;
    int tot = n;
    for (int i = 0; i < n; i++) {
        if (i&1) now = --endd;
        else now = ++strt;
        int x = pos[now] + Query(1, 1, n, pos[now]);
        if (now < x) {
            printf("%d\n", x - now);
            Update(1, 1, n, 1, pos[now]-1, 1);
        } else if (now > x) {
            printf("%d\n", now-x);
            Update(1, 1, n, pos[now]+1, n, -1);
        } else {
            printf("%d\n", 0);
        }
        tot--;
    }

    return 0;
}







