#include <bits/stdc++.h>

using namespace std;

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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010

int par[SZ];
int a[SZ];
int dp[1010][1010];

int findPar(int r) {
    return r == par[r] ? r : findPar(par[r]);
}

int solve(int l, int r) {
    if (l == r) return 1;
    if (l > r) return 0;
    int &ret = dp[l][r];
    if (ret != -1) return ret;
    ret = max(solve(l + 1, r), solve(l, r - 1));
    if (findPar(a[l]) == findPar(a[r])) ret = max(ret, 2 + solve(l + 1, r - 1));
    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, k, m;
    cin >> n >> k >> m;

    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x = findPar(x);
        y = findPar(y);
        if (x != y) par[x] = y;
    }

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    mem(dp, - 1);
    cout << solve(0, m - 1) << endl;

    return 0;
}


