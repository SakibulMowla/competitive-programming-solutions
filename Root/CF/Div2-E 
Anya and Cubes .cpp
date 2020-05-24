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
const ll mod = 1E9;

#define SZ 100010

int n, n1, n2, K;
ll S;
ll a[SZ];
ll f[SZ];
map <ll, ll> v[32];

void bctk (int pos, int k, ll s) {
    if (s > S) return;
    if (pos == n1) {
        v[k][s]++;
        return;
    }
    bctk(pos+1, k, s);
    bctk(pos+1, k, s + a[pos]);
    if (a[pos] <= 19) bctk(pos+1, k+1, s + f[ a[pos] ]);
    return;
}

ll ans;

void solve (int pos, int k, ll s) {
    if (s > S) return;
    if (pos == n) {
        for (int i = 0; i + k <= K; i++) {
            if (v[i].find(S-s) != v[i].end()) {
                ans += v[i][S-s];
            }
        }
        return;
    }
    solve(pos+1, k, s);
    solve(pos+1, k, s + a[pos]);
    if (a[pos] <= 19) solve(pos+1, k+1, s + f[ a[pos] ]);
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    f[0] = 1;
    for (int i = 1; i <= 19; i++) {
        f[i] = (ll)i * f[i-1];
    }

    cin >> n >> K >> S;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    n1 = n / 2;
    n2 = n - n1;

    bctk(0, 0, 0);
    solve(n1, 0, 0);

    cout << ans << '\n';

    return 0;
}







