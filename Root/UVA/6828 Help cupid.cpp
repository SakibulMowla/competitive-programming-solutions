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

typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 1010

int dp[SZ][SZ];
int col[SZ][SZ];
int now;
int val[1010];
int N;

inline int calc (int i, int j) {
    return min(abs(val[i]-val[j]), 24-abs(val[i]-val[j]));
}

int solve (int i, int j) {
//    printf(">i j  =  %d %d\n", i, j);
    int &ret = dp[i][j];
    if (col[i][j] == now) return ret;
    col[i][j] = now;

    if (i > j) return ret = 0;
    if (i + 1 == j) return ret = calc(i, i+1);

    ret = calc(i, i+1) + solve(i+2, j);
    ret = min(ret, calc(j-1, j) + solve(i, j-2));
    ret = min(ret, calc(i, j) + solve(i+1, j-1));

    return ret;
}

int main()
{
    #if defined LOCAL
//       freopen("1.txt", "r", stdin);
//       freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) {
        N = n;
        for (int i = 1; i <= n; i++)
            cin >> val[i];
        sort (val + 1, val + n + 1);
        now++;
        cout << solve(1, n) << '\n';
    }

    return 0;
}


/**
6
-3 -10 -5 11 4 4
2
-6 6
8
0 0 0 0 0 0 0 0
*/




