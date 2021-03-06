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

    double a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    double ans = numeric_limits<double>::max();
    for (int i = 0; i < n; i++) {
        double x, y, v;
        cin >> x >> y >> v;
        ans = min(ans, sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v);
    }
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}





