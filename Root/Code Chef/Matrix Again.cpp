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
const ll mod = (1E7)+7;

#define SZ  110

ll a[SZ][SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    ll ans = 1LL;
    for (int j = 0; j < m; j++) {
        ll sum = 0LL;
        for (int i = 0; i < n; i++) {
            sum = (sum + a[i][j]) % mod;
        }
        sum = (sum + mod) % mod;
        ans = (ans * sum) % mod;
    }

    cout << ans << '\n';

    return 0;
}




