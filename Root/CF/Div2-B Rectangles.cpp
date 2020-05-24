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



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int> (m));
    for (auto &x: a) for (auto &y: x) cin >> y;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) c++;
        }
        ans += (1LL << (ll)c) - 1;
        ans += (1LL << (ll)(m - c)) - 1;
    }
    for (int i = 0; i < m; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == 1) c++;
        }
        ans += (1LL << (ll)c) - 1;
        ans += (1LL << (ll)(n - c)) - 1;
    }
    ans -= n * m;

    cout << ans << endl;

    return 0;
}




