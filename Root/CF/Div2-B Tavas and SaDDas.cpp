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

int dp[12][2][2];
int num[12];
int len;

void prepare (int n) {
    len = 0;
    while (n) {
        num[len++] = n % 10;
        n /= 10;
    }
    return;
}

int solve (int indx, int flag, int strt) {
    if (indx == -1) {
        return 1;
    }

    int &ret = dp[indx][flag][strt];
    if (ret != -1) return ret;

    ret = 0;
    if (!strt) ret += solve(indx - 1, 0, 0);
    int lim = flag ? num[indx] : 7;

    for (int i = 4; i <= lim; i += 3) {
        int nflag;
        if(flag && i == lim) nflag = 1;
        else nflag = 0;
        ret += solve(indx - 1, nflag, 1);
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    prepare(n);
    mem(dp, -1);
    cout << solve(len - 1, 1, 0) - 1 << endl;


    return 0;
}

