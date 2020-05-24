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

ll dp[10][(1<<10)+2][(1<<10)+2];
int col[10][(1<<10)+2][(1<<10)+2];
int now;
int R, C;
char grid[12][12];

ll solve (int r, int maskL, int maskR) {
    //cout << ">> " << r << ' ' << maskL << ' ' << maskR << endl;
    if (r == R) return 1LL;
    ll &ret = dp[r][maskL][maskR];
    if (col[r][maskL][maskR] == now) return ret;
    col[r][maskL][maskR] = now;

    ret = 0;
    maskL >>= 1;
    maskR <<= 1;
    maskR &= ((1<<C) - 1);

    for (int i = 0; i < C; i++) {
        if (grid[r][i] == '*') {
            maskL &= ~(1<<i);
            maskR &= ~(1<<i);
        }
    }

    //cout<<r<<" :: "<<maskL<<" "<<maskR<<endl;

    for (int i = 0; i < C; i++) if (grid[r][i] == '.' && !(maskL & (1<<i)) && !(maskR & (1<<i))) {
        ret += solve(r + 1, maskL | (1<<i), maskR | (1<<i));
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    now++;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    cout << solve(0, 0, 0) << endl;

    return 0;
}







