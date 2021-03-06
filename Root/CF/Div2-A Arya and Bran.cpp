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
const ll mod = 1LL;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int g = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                g = __gcd(g, a[i]);
            }
        }
        if (g > 1) {
            ans += g * __builtin_popcount(mask);
        }
    }

    cout << ans << endl;

    return 0;
}


