#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000007;

#define SZ  100010

int dp[302][100002];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("3.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(false);

    vector <ll> f(310, 1);
    for (int i = 1; i <= 300; i++) {
        f[i] = ((ll)i * f[i-1]) % mod;
    }

    dp[0][0] = 1;
    for (int n = 1; n <= 300; n++) {
        for (int m = n; m <= 100000; m++) {
            dp[n][m] = dp[n][m-n] + dp[n-1][m-n];
            if (dp[n][m] >= mod) {
                dp[n][m] -= mod;
            }
        }
    }

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%lld\n", (dp[n][m] * f[n]) % mod);
    }

    return 0;
}




