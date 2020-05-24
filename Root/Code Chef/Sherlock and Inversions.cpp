#include <bits/stdc++.h>

using namespace  std;

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
const int inf = 1;
const ll mod = 1LL;

#define SZ  20010

int tree[SZ];

void Update (int pos, int n, int val) {
    while (pos <= n) {
        tree[pos] += val;
        pos += pos & -pos;
    }
    return;
}

int Query (int pos) {
    int sum = 0;
    while (pos > 0) {
        sum += tree[pos];
        pos -= pos & -pos;
    }
    return sum;
}

int a[SZ];
int an;
int x[SZ];
int xn;

int BLOCK;

struct data {
    int l, r, indx;
};

vector <data> arr[150];

bool comp (data a, data b) {
    return a.r < b.r;
}

ll ans[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    BLOCK = sqrt(n) + 1;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        x[i-1] = a[i];
    }

    sort(x, x+n);
    xn = unique(x, x+n) - x;

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(x, x+xn, a[i]) - x + 1;
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        data d;
        scanf("%d %d", &d.l, &d.r);
        d.indx = i;
        arr[d.l/BLOCK].pb(d);
    }

    ll tot = 0;
    int curL = 1, curR = 1;

    for (int i = 0; i <= BLOCK+2; i++) {
        if (!sz(arr[i])) continue;

        sort(arr[i].begin(), arr[i].end(), comp);

        for (int j = 0; j < sz(arr[i]); j++) {
            int L = arr[i][j].l;
            int R = arr[i][j].r;

            while (curL < L) {
//                curL
                tot -= (ll)Query(a[curL]-1);
                Update(a[curL], n, -1);
                curL++;
            }
            while (curL > L) {
//                curL-1
                tot += (ll)Query(a[curL-1]-1);
                Update(a[curL-1], n, 1);
                curL--;
            }
            while (curR <= R) {
//                curR
                tot += (ll)Query(n) - (ll)Query(a[curR]);
                Update(a[curR], n, 1);
                curR++;
            }
            while (curR > R + 1) {
//                curR-1
                tot -= (ll)Query(n) - (ll)Query(a[curR-1]);
                Update(a[curR-1], n, -1);
                curR--;
            }

            ans[ arr[i][j].indx ] = tot;
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}




