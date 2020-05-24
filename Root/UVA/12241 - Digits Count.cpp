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

#define SZ 10

int num[SZ];
int dp[SZ][2][2];
int dp1[SZ][2];

int prepare (int n) {
    int len = 0;
    mem(dp, -1);
    mem(dp1, -1);
    while (n) {
        num[len++] = n % 10;
        n /= 10;
    }
    return len - 1;
}

int solve(int pos, int flag) {
    if (pos == -1) return 1;
    int &ret = dp1[pos][flag];
    if (ret != -1) return ret;

    ret = 0;
    int lim = flag? num[pos]: 9;

    for (int i = 0; i <= lim; i++) {
        int nflag = (flag && i == lim);
        ret += solve(pos - 1, nflag);
    }

    return ret;
}

int solve (int pos, int flag, int strt, int digit) {
    if (pos == -1) return 0;
    int &ret = dp[pos][flag][strt];
    if (ret != -1) return ret;

    ret = 0;
    int lim = flag? num[pos]: 9;

    for (int i = 0; i <= lim; i++) {
        int nflag = (flag && i == lim);
        ret += solve(pos - 1, nflag, strt || (i != 0), digit);
        if (i == digit) {
            if ((i == 0 && strt) || (i != 0)) ret += solve(pos - 1, nflag);
        }
    }

    return ret;
}

int solve (int a, int b, int digit) {
    int ans = solve(prepare(b), 1, 0, digit) - solve(prepare(a - 1), 1, 0, digit);
    return ans;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int a, b;
    while (cin >> a >> b && (a + b)) {
        for (int digit = 0; digit < 10; digit++) {
            if (digit) cout << ' ';
            cout << solve(a, b, digit);
        }
        cout << endl;
    }


    return 0;
}

