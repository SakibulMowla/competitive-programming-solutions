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
const ll mod = 1000000007;

#define SZ 1010

ll dp[SZ][SZ];

ll solve (int even, int odd, int k) {
    if (k == 0) {
        return (odd == 0);
    }

    ll &ret = dp[even][k];
    if (ret != -1) return ret;

    ret = 0;
    if (even) ret = (even * solve(even - 1, odd + 1, k - 1)) % mod;
    if (odd) ret = (ret + (odd * solve(even + 1, odd - 1, k - 1)) % mod) % mod;

    return ret;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;

        int even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x & 1) odd++;
            else even++;
        }

        mem(dp, -1);
        cout << "Case #" << cs + 1 << ": " << solve(even, odd, k) << endl;
    }


    return 0;
}







