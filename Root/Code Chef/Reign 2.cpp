#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const ll inf = 1E18;
const ll mod = 1LL;

#define SZ  100010

bool comp(pll a, pll b) {
    return a.Y > b.Y;
}

ll solve (int n, int k, vector <pll> &a, vector < vector <ll> > &dp) {
    if (k == 0) return 0;
    if (n + 1 < k || n == -1) return -inf;

    ll &ret = dp[n][k];
    if (ret != -inf) return ret;

    return ret = max(solve(n - 1, k, a, dp), a[n].X + (k - 1LL) * a[n].Y + solve(n - 1, k - 1, a, dp));
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector <pll> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i].X;
        }

        for (int i = 0; i < n; i++) {
            cin >> a[i].Y;
        }

        sort(a.begin(), a.end(), comp);

        vector < vector <ll> > dp(n+2, vector <ll> (n+2, -inf));

        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << solve (n - 1, i + 1, a, dp);
        }
        cout << endl;
    }


    return 0;
}




