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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t, ans = 0;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        if (((a <= 56 && b <= 45 && c <= 25) || (a + b + c <= 125)) && d <= 7) {
            cout << 1 << endl;
            ans++;
        } else {
            cout << 0 << endl;
        }
    }

    cout << ans << endl;


    return 0;
}







