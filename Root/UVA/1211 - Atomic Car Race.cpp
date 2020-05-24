#include <bits/stdc++.h>

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
const ll mod = 1LL;

#define SZ  110

int a[SZ];
double dp[SZ];
bool col[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r;
    double b, v, e, f;

    while (cin >> n && n) {
        a[0] = 0;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            col[i] = 0;
        }
        cin >> b >> r >> v >> e >> f;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int dist = a[j] - a[i];
                double tym = 0;
                for (int x = 0; x < dist; x++) {
                    if (x >= r) tym += 1.0/ (v - e * (double)(x - r));
                    else tym += 1.0 / (v - f * (double)(r - x));
                }
                if (i) tym += b;
                if (col[j] == 0 || dp[j] > dp[i] + tym) {
                    dp[j] = dp[i] + tym;
                    col[j] = 1;
                }
            }
        }

        cout << fixed << setprecision(4) << dp[n] << '\n';
    }


    return 0;
}





