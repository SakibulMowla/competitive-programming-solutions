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
        freopen("C-small-1-attempt0.in", "r", stdin);
        freopen("2.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;

        double u;
        cin >> u;

        vector <double> a(n);
        for (auto &x: a) cin >> x;

        sort(a.begin(), a.end());
        a.push_back(1.0);

        for (int i = 1; i <= n; i++) {
            double need = i * (a[i] - a[i - 1]);
            if (need > u) {
                for (int j = 0; j < i; j++)
                    a[j] += u / (double)i;
                break;
            } else {
                u -= need;
                for (int j = 0; j < i; j++)
                    a[j] += (a[i] - a[i - 1]);
            }
        }

        double ans = 1.0;
        for (int i = 0; i < n; i++) ans *= a[i];

        cout << fixed << setprecision(10) << "Case #" << cs + 1 << ": " << ans << endl;
    }

    return 0;
}






