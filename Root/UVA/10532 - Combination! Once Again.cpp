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

#define SZ 52

int a[SZ];
ll dp[SZ][SZ];
int col[SZ][SZ];
int now;

ll solve (int pos, int lft) {
    ll &ret = dp[pos][lft];
    if (col[pos][lft] == now) return ret;

    if (lft == 0) return ret = 1LL;
    if (pos == 0) return ret = 0LL;

    col[pos][lft] = now;
    ret = 0;

    for (int i = 0; i <= a[pos]; i++) {
        if (lft - i >= 0) {
            ret += solve(pos - 1, lft - i);
        }
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, m, cs = 0;

    while (cin >> n >> m && n) {
        mem(a, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x]++;
        }

        cout << "Case " << ++cs << ":" << endl;

        now++;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cout << solve(n, x) << endl;
        }
    }


    return 0;
}







