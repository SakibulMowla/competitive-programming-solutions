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

#define SZ 20

ll dp[SZ][SZ];
char s[SZ][SZ];

int main() {
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    dp[0][0] = 1LL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i + 1; k < n; k++) {
                for (int l = j + 1; l < m; l++) {
                    if (s[i][j] != s[k][l]) {
                        dp[k][l] += dp[i][j];
                    }
                }
            }
        }
    }

    printf("%lld\n", dp[n-1][m-1]);

    return 0;
}






