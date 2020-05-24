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
const ll mod = 242121643LL;


#define SZ 110


int main() {
//    #if defined JESI
        freopen("game.in", "r", stdin);
        freopen("game.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    vector < vector <ll> > C(SZ, vector <ll> (SZ, 0));

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) C[i][j] = 1;
            else if (j == i) C[i][j] = 1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }

    int n, k;
    while (cin >> n >> k && (n + k)) {
        int one = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            one += (x == 1);
        }

        ll ans = 0;
        int left = n - one;

        for (int i = 1; i <= min(one, k); i += 2) {
            if (left + i >= k) {
                ll tmp = (C[one][i] * C[left][k-i]) % mod;
                ans = (ans + tmp) % mod;
            }
        }

        cout << ans << endl;
    }

    return 0;
}





