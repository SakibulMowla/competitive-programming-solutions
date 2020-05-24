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

int tree[SZ];

void update (int x, int val, int n) {
    while (x <= n) {
        tree[x] += val;
        x += (x & -x);
    }
}

int query (int x) {
    int v = 0;
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

    int a[SZ];
    int x[SZ];
    int xn, n;
    ll k;

    scanf("%d %I64d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        x[i-1] = a[i];
    }

    if (k == 0) {
        k = n;
        printf("%I64d\n", (k * (k+1LL))/2LL);
        return 0;
    }

    sort(x, x+n);
    xn = unique(x, x+n) - x;

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(x, x+xn, a[i]) - x + 1;
    }

    int j = 1;
    ll ans = 0;
    ll inv = 0;

    for (int i = 1; i <= n; i++) {
        for (; j <= n && inv < k; j++) {
            inv += (ll)query(n) - (ll)query(a[j]);
            update(a[j], 1, n);
        }

        if (inv >= k) {
            ans += (ll)(n - j + 2);
        }

        inv -= query(a[i]-1);
        update(a[i], -1, n);
    }

    printf("%I64d\n", ans);

    return 0;
}




