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

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    int m;
    cin >> m;

    int ans = -1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > sum) {
            ans = u;
            break;
        }
        if (v >= sum) {
            ans = sum;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}




