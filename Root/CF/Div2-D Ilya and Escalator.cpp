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

#define SZ 2010

double p;
double dp[SZ][SZ][2];
bool col[SZ][SZ][2];

double solve (int n, int t, int k) {
    double &ret = dp[n][t][k];
    if (col[n][t][k]) return ret;
    col[n][t][k] = 1;
    if (n == 0 || t == 0) return ret = (double)k;
    return ret = (double)k + p * solve(n-1, t-1, 1) + (1.0 - p) * solve(n, t-1, 0);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif
    FAST
    int n, t;
    while (cin >> n >> p >> t) {
        mem(col, 0);
        cout << fixed << setprecision(15) << solve(n, t, 0) << '\n';
    }


    return 0;
}







