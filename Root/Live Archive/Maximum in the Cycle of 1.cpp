#include <bits/stdc++.h>

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
const ll mod = 1LL;

#define SZ  22

ll f[SZ];
ll c[SZ][SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    f[0] = 1;
    for (int i = 1; i <= 20; i++) {
        f[i] = (ll)i * f[i-1];
    }

    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) c[i][j] = 1;
            else if (j == 0) c[i][j] = 1;
            else c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int test, n, k;
        cin >> test >> n >> k;

        ll ans = 0;
        if (k == 1) {
            ans = f[n-1];
        } else {
            ans = f[n-2];
            for (int len = 3; len <= k; len++) {
                ans += c[k-2][len-2] * f[len-1] * f[n-len];
            }
        }

        cout << test << ' ' << ans << '\n';
    }

    return 0;
}


