#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  55

class Decipherability {
public:
    int n;
    string a;
    int dp[SZ][SZ][SZ][2];
    int solve (int pos1, int pos2, int k, int dif) {
        if (k == 0) return dif;
        if (pos1 == n || pos2 == n) return 0;
        int &ret = dp[pos1][pos2][k][dif];
        if (ret != -1) return ret;
        ret = max(solve(pos1+1, pos2, k, dif), solve(pos1, pos2+1, k, dif));
        if (a[pos1] == a[pos2]) ret = max(ret, solve(pos1+1, pos2+1, k-1, dif || (pos1 != pos2)));
        return ret;
    }
    string check(string s, int k) {
        if (k == sz(s)) return "Certain";
        a = s;
        n = sz(s);
        mem(dp, -1);
        return solve(0, 0, n-k, 0) ? "Uncertain" : "Certain";
    }

};
