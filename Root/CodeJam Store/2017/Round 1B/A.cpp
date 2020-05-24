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
//    #if defined JESI
//        freopen("A-large.in", "r", stdin);
//        freopen("2.txt", "w", stdout);
//        freopen("A-small-attempt0.in", "r", stdin);
//        freopen("2.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int d, n;
        cin >> d >> n;
        vector <pii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].X >> a[i].Y;
        }
        sort(a.begin(), a.end());
        double mx = 0;
        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, double(d - a[i].X) / (double)a[i].Y);
        }
        cout << fixed << setprecision(10) << "Case #" << cs + 1 << ": " << (double)d / mx << endl;
    }

    return 0;
}






