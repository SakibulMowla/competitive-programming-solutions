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

int decider(string &a, string &b) {
    int l1 = sz(a), l2 = sz(b);
    for (int i = 0; i < min(l1, l2); i++) {
        if (a[i] < b[i])
            return 1;
        else if (a[i] > b[i])
            return 0;
    }
    if (l1 == l2 || l1 < l2)
        return 1;
    return 0;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <ll> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    vector <string> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        reverse(b[i].begin(), b[i].end());
    }

    vector <int> d[n][2];

    for (int i = 0; i < n - 1; i++) {
        d[i][0].pb(0);
        d[i][0].pb(0);
        d[i][1].pb(0);
        d[i][1].pb(0);
        d[i][0][0] = decider(a[i], a[i + 1]);
        d[i][0][1] = decider(a[i], b[i + 1]);
        d[i][1][0] = decider(b[i], a[i + 1]);
        d[i][1][1] = decider(b[i], b[i + 1]);
//        cout << ">> " << i << ' ' << d[i][0][0] << ' ' << d[i][0][1] << ' ' << d[i][1][0] << ' ' << d[i][1][1] << endl;
    }

    vector < vector <ll> > dp(n, vector <ll>(2, numeric_limits <ll> :: max()));
    dp[n-1][0] = 0;
    dp[n-1][1] = cost[n-1];
    for (int i = n - 2; i >= 0; i--) {
        if (d[i][0][0]) dp[i][0] = dp[i+1][0];
        if (d[i][0][1]) dp[i][0] = min(dp[i][0], dp[i+1][1]);
        if (d[i][1][0] && dp[i+1][0] < numeric_limits <ll> :: max()) dp[i][1] = cost[i] + dp[i+1][0];
        if (d[i][1][1] && dp[i+1][1] < numeric_limits <ll> :: max()) dp[i][1] = min(dp[i][1], cost[i] + dp[i+1][1]);
    }

    cout << (min(dp[0][0], dp[0][1]) >= numeric_limits <ll> :: max()? -1: min(dp[0][0], dp[0][1])) << endl;

    return 0;
}





