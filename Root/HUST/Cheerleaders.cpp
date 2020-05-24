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
const int mod = 1000007;

#define SZ 100010

int calc (int mask, int n, int m) {
    int ret = 0;
    if (mask & (1<<0)) {
        ret += m;
        if (mask & (1<<3))
            ret--;
    }
    if (mask & (1<<1)) {
        ret += n;
        if (mask & (1<<0))
            ret--;
    }
    if (mask & (1<<2)) {
        ret += m;
        if (mask & (1<<1))
            ret--;
    }
    if (mask & (1<<3)) {
        ret += n;
        if (mask & (1<<2))
            ret--;
    }
    return ret;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    vector < vector <int> > C(405, vector <int> (405, 0));

    for (int i = 0; i <= 400; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) C[i][j] = 1;
            else if (j == 1) C[i][j] = i;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        int lim = (1<<4), ans = 0;

        for (int mask = 0; mask < lim; mask++) {
            int lft = n * m - calc(mask, n, m);
            if (k > lft) continue;

            if (__builtin_popcount(mask) & 1) ans = ans - C[lft][k];
            else ans = ans + C[lft][k];

            if (ans >= mod) ans -= mod;
            if (ans < 0) ans += mod;
        }

        printf("Case %d: %d\n", cs + 1, ans);
    }


    return 0;
}







