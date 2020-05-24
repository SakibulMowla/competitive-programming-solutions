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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

int dp[60][60][110];
int row, col;

bool ok(int m1, int m2, int m3) {
    for (int c = 0; c < col; c++) {
        if (m3 & (1<<c)) {
            if (m2 & (1<<c))
                if (m1 & (1<<c)) {
                    return false;
            }
        }
    }
    for (int i = 2; i < col; i++) {
        if (m3 & (1<<i)) {
            if (m3 & (1<<(i-1))) {
                if (m3 & (1<<(i-2))) {
                    return false;
                }
            }
        }
    }
    return true;
}

int solve (int m1, int m2, int r) {
    if (r == 0) return 0;
    int &ret = dp[m1][m2][r];
    if (ret != -1) return ret;
    ret = 0;
    for (int mask = 0; mask < (1 << col); mask++) {
        if (ok(m1, m2, mask)) {
            ret = max(ret, __builtin_popcount(mask) + solve(m2, mask, r-1));
        }
    }
    return ret;
}

int main() {
//    #if defined JESI
        freopen("B-small-attempt0.in", "r", stdin);
        freopen("4.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> row >> col;
        mem(dp, -1);
        cout << "Case #" << cs + 1 << ": " << solve(0, 0, row) << endl;
    }

    return 0;
}



