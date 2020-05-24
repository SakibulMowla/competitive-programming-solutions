#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

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

void prepare (ull a, ull b, int n, vector <int>& num) {
    a *= 10;
    int pos = 0;
    while (pos < n) {
        while (a < b && pos < n) {
            num.pb(0);
            pos++;
            a *= 10;
        }
        if (pos < n) {
            num.pb(a / b);
            a %= b;
            pos++;
        }
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ull a, b;
        int n, p;
        cin >> a >> b >> n >> p;

        vector <int> num;
        prepare(a, b, n, num);

        vector <vector <ll>> dp(2, vector <ll> (p + 2, 0));
        dp[0][0] = 1;

        ll ans = 0;
        for (int i = 0, k = 0; i < n; i++, k ^= 1) {
            for (int j = 0; j < p; j++) {
                dp[!k][j] = 0;
            }
            dp[!k][0] = 1;
            for (int j = 0; j < p; j++) {
                if (dp[k][j]) {
                    dp[!k][(j * 10 + num[i]) % p] += dp[k][j];
                }
            }
////            for (int j = 0; j < p; j++) {
////                cout << ">> " << i + 1 << ' ' << j << ' ' << dp[i + 1][j] << endl;
////            }
            ans += dp[!k][0] - 1;
        }


        cout << ans << endl;
    }


    return 0;
}





