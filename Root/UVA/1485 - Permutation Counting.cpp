#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1000000007LL;

#define SZ  1002

ll dp[SZ][SZ];

ll solve (int n, int k) {
    ll &ret = dp[n][k];
    if (ret != -1) return ret;

    if (k == 0) return ret = 1LL;
    if (n == 0) return ret = 0LL;

    ret = solve(n - 1, k);
    ret = (ret + ((ll)k * solve(n - 1, k)) % mod) % mod;
    ret = (ret + ((ll)(n - k) * solve(n - 1, k - 1)) % mod) % mod;

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    mem(dp, -1);

    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        printf("%lld\n", solve(n, k));
    }

    return 0;
}



