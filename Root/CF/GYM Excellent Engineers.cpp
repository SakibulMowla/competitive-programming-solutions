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
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1E8;
const ll mod = 1LL;

#define SZ 100010
#define SZ1 4*100010

struct data {
    int b, c;
};

data a[SZ];
int mnz[SZ1];

void build (int node, int b, int e) {
    if(b == e) {
        mnz[node] = inf;
        return;
    }
    int mid = (b + e) >> 1;
    build(2*node, b, mid);
    build(2*node+1, mid+1, e);
    mnz[node] = min(mnz[2*node], mnz[2*node+1]);
    return;
}

int query (int node, int b, int e, int f, int t) { ///node, begin, end, from, to
    if(b>=f && e<=t) return mnz[node];
    int mid = (b + e) >> 1;
    int ret = inf;
    if(f <= mid) ret = min(ret, query(2*node, b, mid, f, t));
    if(t > mid) ret = min(ret, query(2*node+1, mid+1, e, f, t));
    return ret;
}

void update (int node, int b, int e, int x, int val) {
    if(b == e) {
        mnz[node] = val;
        return;
    }
    int mid = (b + e) >> 1;
    if(x <= mid) update(2*node, b, mid, x, val);
    else update(2*node+1, mid+1, e, x, val);
    mnz[node] = min(mnz[2*node], mnz[2*node+1]);
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            scanf("%d %d", &a[x].b, &a[x].c);
        }

        build(1, 1, n);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int mn = query(1, 1, n, 1, a[i].b);
            if(a[i].c < mn) ans++;
            update(1, 1, n, a[i].b, a[i].c);
        }

        printf("%d\n", ans);
    }

    return 0;
}









