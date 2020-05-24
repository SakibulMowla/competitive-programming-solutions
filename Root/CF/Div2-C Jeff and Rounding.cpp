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

#define SZ 4010

int arr[SZ];
int dp[SZ][SZ/2];

int solve (int pos, int k, int p) {
    if (pos == -1) return 0;
    int &ret = dp[pos][k];
    if (ret != -1) return ret;

    int ret1 = 1E8, ret2 = 1E8;
    if (k) ret1 = solve(pos-1, k-1, p) - arr[pos];
    if (p) ret2 = solve(pos-1, k, p-1) + (1000-arr[pos])%1000;

    if (abs(ret1) < abs(ret2)) ret = ret1;
    else ret = ret2;

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    for (int i = 0; i < 2 * n; i++) {
        scanf("%*d.%d", &arr[i]);
    }

    mem(dp, -1);
    cout << fixed << setprecision(3) << abs(solve(2*n-1, n, n)) / 1000.0 << '\n';

    return 0;
}






