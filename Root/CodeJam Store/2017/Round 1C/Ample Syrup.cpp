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

#define SZ 1010

double dp[SZ][SZ];
bool col[SZ][SZ];

vector <pair <double, double> > RH;

double solve (int indx, int left) {
    if (left == 0) return 0;
    if (indx == -1) return -1E16;
    if (col[indx][left] == 1) return dp[indx][left];
    col[indx][left] = 1;
    dp[indx][left] = solve(indx - 1, left);
    dp[indx][left] = max(dp[indx][left], solve(indx - 1, left - 1) + RH[indx].X * RH[indx].Y);
    return dp[indx][left];
}

int main() {
//    #if defined JESI
        freopen("A-large.in", "r", stdin);
        freopen("2.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    double pi = acos(-1.00);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;

        RH = vector <pair <double, double> >(n);

        for (int i = 0; i < n; i++) {
            cin >> RH[i].X >> RH[i].Y;
        }

        sort(RH.begin(), RH.end());
        mem(col, 0);

        double ans = 0;
        for (int i = k - 1; i < n; i++) {
            ans = max(ans, solve(i - 1, k - 1) * 2.0 * pi + pi * RH[i].X * RH[i].X + RH[i].X * RH[i].Y * 2.0 * pi);
        }

        cout << fixed << setprecision(10) << "Case #" << cs + 1 << ": " << ans << endl;
    }

    return 0;
}






