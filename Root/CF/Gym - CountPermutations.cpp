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

#define SZ  110

int n, k;
ll dp[(1<<15)+10][16];

ll solve (int mask, int pre) {
    if (!mask) return 1;
    ll &ret = dp[mask][pre];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < n; i++) {
        if ((mask & (1<<i)) && abs(i - pre) <= k) {
            ret += solve(mask & ~(1<<i), i);
        }
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> n >> k;

        mem(dp, -1);
        int lim = (1<<n) - 1;

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += solve(lim & ~(1<<i), i);
        }

        cout << ans << '\n';
    }


    return 0;
}




