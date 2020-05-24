#include "bits/stdc++.h"

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
const int inf = 1E9;
const ll mod = 1000000007LL;

#define SZ  1010

ll dp[SZ][SZ];
int N;

ll solve (int one, int k) {
    ll &ret = dp[one][k];
    if(~ret) return ret;
    if(!k) return ret = !one;

    int zero = N - one;
    ret = 0LL;

    if (one) ret = (ret + ((ll)one * solve(one-1, k-1)) % mod ) % mod;
    if (zero) ret = (ret + ((ll)zero * solve(one+1, k-1)) % mod) % mod;

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;
        N = n;

        int one = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            one += x;
        }

        mem(dp, -1);
        cout << "Case #" << cs+1 << ": " << solve(one, k) << '\n';
    }


    return 0;
}







