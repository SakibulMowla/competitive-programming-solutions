#include <bits/stdc++.h>

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
const ll mod = 1E9 + 7;

#define SZ  3010

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    vector < vector <ll> > dp(SZ, vector <ll> (SZ, 0));

    dp[1][1] = 1;
    for (int n = 2; n <= 3000; n++) {
        int lim = (n + 1) / 2;
        for (int k = 1; k <= lim; k++) {
            dp[n][k] = (dp[n - 1][k] * k * 2 + dp[n - 1][k - 1] * (n - 2 * (k - 1))) % mod;
        }
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;

        ll ans = 0;
        for (int i = 0; i <= n - k; i++) {
            ans += dp[n][i];
            if (ans >= mod) ans -= mod;
        }

        cout << ans << endl;
    }

    return 0;
}


