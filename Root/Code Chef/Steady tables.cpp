#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000000LL;

#define SZ  100010

ll C[4010][4010];
ll dp[2010][2010];
int col[2010][2010];
int cnow;
int n, m;

ll solve (int row, int now) {
    if (row == n) return 1LL;

    ll &ret = dp[row][now];
    if (col[row][now] == cnow) return ret;
    col[row][now] = cnow;

    ret = (C[m+now-1][now] * solve(row + 1, now)) % mod;
    if (now + 1 <= m) ret = ret + solve(row, now+1);
    if (ret >= mod) ret -= mod;

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    for (int i = 0; i <= 4000; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) C[i][j] = 1;
            else if (j == 1) C[i][j] = i;
            else C[i][j] = C[i-1][j] + C[i-1][j-1];
            if (C[i][j] >= mod) C[i][j] -= mod;
        }
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> n >> m;
        cnow++;
        cout << solve(0, 0) << endl;
    }

    return 0;
}





