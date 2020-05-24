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

vector <pii> a;

int dp[22][12];

int solve (int pos, int tym) {
    if (pos == -1) return 0;
    int &ret = dp[pos][tym];
    if (ret != -1) return ret;
    ret = solve(pos - 1, tym);
    if (a[pos].X >= tym) ret = max(ret, 1 + solve(pos - 1, a[pos].Y));
    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int s, t;
        clr(a);
        while (cin >> s >> t && (s + t)) {
            a.pb({s, t});
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        mem(dp, -1);
        cout << solve(sz(a) - 1, 0) << endl;
    }


    return 0;
}







