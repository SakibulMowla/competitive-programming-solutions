#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010

int f (char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    else return ch - 'A' + 10;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> a(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = f(s[0]) * 16 + f(s[1]);
    }

    if (n <= 2048) {
        ll ans = 0;
        vector < vector <ll> > dp(n + 2, vector <ll> (n + 2, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + (ll)((i-1) ^ a[j-1]));
                ans = max(ans, dp[i][j]);
//                cout << ">> " << i << ' ' << j << ' ' << dp[i][j] << ' ' << a[j-1] << endl;
            }
        }
        cout << ans << endl;
    } else {
        ll ans = 0;
        for (int m = n; m >= n - 256; m--) {
            ll tot = 0;
            for (int i = 0; i < m; i++) {
                tot += (ll)(i ^ a[i]);
            }
            ans += ;
        }
        cout << ans << endl;
    }

    return 0;
}




