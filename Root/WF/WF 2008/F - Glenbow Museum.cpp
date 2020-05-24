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

#define SZ 1010

ll dp[SZ][SZ][2][2];

ll solve (int a, int b, int pre, int first) {
    if (a < 0 || b < 0) return 0LL;

    ll &ret = dp[a][b][pre][first];
    if (~ret) return ret;

    if(!(a+b)) {
        if (pre && first) return ret = 0LL;
        return ret = 1LL;
    }

    ret = solve(a-1, b, 0, first);
    if (!pre) ret += solve(a, b-1, 1, first);

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    mem(dp, -1);

    int test = 0, n;

    while (scanf("%d", &n) == 1 && n) {
        int a = n / 2;
        int b = n / 2;
        a += 2;
        b -= 2;
        if (n & 1) printf("Case %d: 0\n", ++test);
        else printf("Case %d: %lld\n", ++test, solve(a-1, b, 0, 0) + (b ? solve(a, b-1, 1, 1) : 0));
    }


    return 0;
}






