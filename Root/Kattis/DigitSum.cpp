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

#define SZ 50

int num[SZ];
int len;

void prep (ll n) {
    len = 0;
    while (n) {
        num[len++] = n % 10;
        n /= 10;
    }
    return;
}

ll dp[SZ][2];
ll dp1[SZ][2];

ll solveAssist (int pos, int flag) {
    if (pos == -1) return 1;
    ll &ret = dp1[pos][flag];
    if (ret != -1) return ret;

    ret = 0;
    int lim = flag ? num[pos] : 9;

    for (int i = 0; i <= lim; i++) {
        int nflag = (flag && i == lim);
        ret += solveAssist(pos-1, nflag);
    }

    return ret;
}

ll solve (int pos, int flag) {
    if (pos == -1) return 0;
    ll &ret = dp[pos][flag];
    if (ret != -1) return ret;

    int lim = flag ? num[pos] : 9;
    ret = 0;

    for (int i = 0; i <= lim; i++) {
        int nflag = (flag && i == lim);
        ret += solve(pos-1, nflag);
        if (i) ret += (ll)i * solveAssist(pos-1, nflag);
    }

    return ret;
}

ll calc (ll n) {
    if (n > 0) {
        mem(dp, -1);
        mem(dp1, -1);
        prep(n);
        return solve(len-1, 1);
    } else {
        return 0;
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", calc(b) - calc(a-1));
    }


    return 0;
}






