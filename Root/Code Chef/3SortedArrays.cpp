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

#define SZ  100010

struct data {
    int val, idx;
};

bool comp (data p, data q) {
    return p.val <= q.val;
}

data a[SZ];
data b[SZ];
data c[SZ];

void read (int &n, data d[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i].val);
        d[i].idx = i;
    }
}

ll yy[SZ];
ll xx[SZ];
ll tree[SZ];

void update(int x, ll v, int n) {
    while (x <= n) {
        tree[x] += v;
        x += (x & -x);
    }
}

ll query(int x) {
    ll v = 0;
    while (x > 0) {
        v += tree[x];
        x -= (x & -x);
    }
    return v;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int p, q, r;

        read(p, a);
        read(q, b);
        read(r, c);

        sort(a + 1, a + p + 1, comp);
        sort(b + 1, b + q + 1, comp);
        sort(c + 1, c + r + 1, comp);

        mem(tree, 0);
        int j = r;

        for (int i = q; i >= 1; i--) {
            for (; j >= 1; j--) {
                if (c[j].val < b[i].val) {
                    break;
                }
                update(c[j].idx, 1, max(r, q));
            }
            yy[ b[i].idx ] = (r >= b[i].idx - 1) ? query(r) - query(b[i].idx - 1) : 0;
        }

        mem(tree, 0);
        j = 1;

        for (int i = 1; i <= q; i++) {
            for (; j <= p; j++) {
                if (a[j].val > b[i].val) {
                    break;
                }
                update(a[j].idx, 1, max(p, q));
            }
            xx[ b[i].idx ] = query(b[i].idx);
        }

        ll ans = 0;
        for (int i = 1; i <= q; i++) {
            ans += xx[i] * yy[i];
        }

        printf("%lld\n", ans);
    }

    return 0;
}


/*
2

3
1 2 3
3
3 4 5
3
7 8 9

3
1 5 6
3
2 3 4
3
7 8 9

2
1 2
2
3 4
3
5 6 7

*/

