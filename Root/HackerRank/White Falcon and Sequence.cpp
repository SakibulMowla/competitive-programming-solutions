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
const ll inf = 1E16;
const ll mod = 1E9;

#define SZ 3010

ll dp[SZ][SZ];
int col[SZ][SZ];
int now;
ll a[SZ];

ll solve (int i, int j) {
    if (i >= j) return 0LL;

    ll &ret = dp[i][j];
    if (col[i][j] == now) return ret;
    col[i][j] = now;

    solve(i + 1, j);
    solve(i, j - 1);
    ret = a[i] * a[j] + max(0LL, solve(i + 1, j - 1));

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    now++;
    solve(0, n - 1);

    ll ans = -inf;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    printf("%lld\n", ans);

    return 0;
}







