#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;

const ll inf = 1;
const ll mod = 1E9;

const ll h1 = 730929037LL;
const ll h2 = 999727999LL;
const ll h3 = 317202713LL;


#define SZ 100010

ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

string arr;

struct data {
    ll a, b, c;
    data () {}
    data (ll _a, ll _b, ll _c) {
        a = _a, b = _b, c = _c;
    }
};

data tree[4*SZ];
data Ten[SZ];

inline void Merge (int &node, int &mid, int &e) {
    tree[node].a = ((tree[2 * node].a * Ten[e - mid].a) % h1 + tree[2 * node + 1].a) % h1;
    tree[node].b = ((tree[2 * node].b * Ten[e - mid].b) % h2 + tree[2 * node + 1].b) % h2;
    tree[node].c = ((tree[2 * node].c * Ten[e - mid].c) % h3 + tree[2 * node + 1].c) % h3;
    return;
}

void build (int node, int b, int e) {
    if (b == e) {
        tree[node].a = arr[b-1] - '0';
        tree[node].b = arr[b-1] - '0';
        tree[node].c = arr[b-1] - '0';
    } else {
        int mid = (b + e) >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);
        Merge(node, mid, e);
    }
    return;
}

ll lazy[4*SZ];
data digit[10][SZ];

inline void propagate (int &node, int &b, int &mid, int &e) {
    if (b == e) return;
    lazy[2 * node] = lazy[2 * node + 1] = lazy[node];
    tree[2 * node] = digit[lazy[node]][mid-b+1];
    tree[2 * node + 1] = digit[lazy[node]][e-mid];
    lazy[node] = -1;
    return;
}

void update (int node, int b, int e, int f, int t, ll d) {
    if (b >= f && e <= t) {
        tree[node] = digit[d][e-b+1];
        if (b != e) lazy[node] = d;
        else lazy[node] = -1;
    } else {
        int mid = (b + e) >> 1;
        if (lazy[node] != -1) propagate(node, b, mid, e);
        if (f <= mid) update(2 * node, b, mid, f, t, d);
        if (t > mid) update(2 * node + 1, mid + 1, e, f, t, d);
        Merge(node, mid, e);
    }
    return;
}

using pll = pair <ll , data>;

pll query (int node, int b, int e, int f, int t) {
    if (b >= f && e <= t) {
        return {e-b+1, tree[node]};
    } else {
        int mid = (b + e) >> 1;
        if (lazy[node] != -1) propagate(node, b, mid, e);
        pll xx, yy;
        int c1 = 0, c2 = 0;
        if (f <= mid) xx = query(2 * node, b, mid, f, t), c1 = 1;
        if (t > mid) yy = query(2 * node + 1, mid + 1, e, f, t), c2 = 1;

        Merge(node, mid, e);

        if (c1 + c2 == 1) {
            if (c1) return xx;
            return yy;
        } else {
            pll zz;
            zz.X = xx.X + yy.X;
            zz.Y.a = ((xx.Y.a * Ten[yy.X].a) % h1 + yy.Y.a) % h1;
            zz.Y.b = ((xx.Y.b * Ten[yy.X].b) % h2 + yy.Y.b) % h2;
            zz.Y.c = ((xx.Y.c * Ten[yy.X].c) % h3 + yy.Y.c) % h3;
            return zz;
        }
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    ll a = 1, b = 1, c = 1;
    Ten[0].a = Ten[0].b = Ten[0].c = 1;

    for (int i = 0; i < 10; i++) {
        digit[i][1].a = i;
        digit[i][1].b = i;
        digit[i][1].c = i;
        for (int j = 2; j <= 100000; j++) {
            digit[i][j].a = ((digit[i][j-1].a * 10LL) + (ll)i) % h1;
            digit[i][j].b = ((digit[i][j-1].b * 10LL) + (ll)i) % h2;
            digit[i][j].c = ((digit[i][j-1].c * 10LL) + (ll)i) % h3;
        }
    }

    for (int i = 1; i <= 100000; i++) {
        Ten[i].a = (Ten[i-1].a * 10LL) % h1;
        Ten[i].b = (Ten[i-1].b * 10LL) % h2;
        Ten[i].c = (Ten[i-1].c * 10LL) % h3;
    }

    int n, m, k;
    cin >> n >> m >> k;
    cin >> arr;

    build(1, 1, n);
    mem(lazy, -1);

    for (int i = 0; i < m + k; i++) {
        int k, l, r, d;
        cin >> k >> l >> r >> d;
        if (k == 1) {
            update(1, 1, n, l, r, d);
        } else {
            if (l + d > r) cout << "YES" << endl;
            else {
                pll a1 = query(1, 1, n, l, r - d);
                pll a2 = query(1, 1, n, l + d, r);
                if (a1.Y.a == a2.Y.a && a1.Y.b == a2.Y.b && a1.Y.c == a2.Y.c) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}


