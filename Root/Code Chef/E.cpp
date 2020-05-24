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
const ll mod = (1E9)+7;

#define SZ 510

ll dp[2][SZ][SZ];
char s[SZ][SZ];


int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i]+1);
    }

    int now = 0;
    dp[now][1][n] = 1;

    int step;
    for (step = 1; step < (n + m - 1) / 2 + (n + m - 1) % 2; step++) {
        now ^= 1;
        memset(dp[now], 0, sizeof dp[now]);
        for (int row1 = 1; row1 <= n; row1++) {
            int col1 = step - (row1 - 1);
            if (col1 < 1 || col1 > m) continue;
            for (int row2 = 1; row2 <= n; row2++) {
                int col2 = m - (step - (n - row2)) + 1;
                if (col2 < 1 || col2 > m) continue;
                if (s[row1][col1] != s[row2][col2]) continue;
                ll val = dp[now^1][row1][row2];
                dp[now][row1 + 1][row2 - 1] = (dp[now][row1 + 1][row2 - 1] + val) % mod;
                dp[now][row1 + 1][row2] = (dp[now][row1 + 1][row2] + val) % mod;
                dp[now][row1][row2 - 1] = (dp[now][row1][row2 - 1] + val) % mod;
                dp[now][row1][row2] = (dp[now][row1][row2] + val) % mod;
            }
        }
    }

    ll ans = 0;
    for (int row1 = 1; row1 <= n; row1++) {
        int col1 = step - (row1 - 1);
        if (col1 < 1 || col1 > m) continue;
        for (int row2 = 1; row2 <= n; row2++) {
            int col2 = m - (step - (n - row2)) + 1;
            if (col2 < 1 || col2 > m) continue;
            if (row1 <= row2 && col1 <= col2 && s[row1][col1] == s[row2][col2]) {
                ans = (ans + dp[now][row1][row2]) % mod;
            }
        }
    }

    printf("%I64d\n", ans);

    return 0;
}

