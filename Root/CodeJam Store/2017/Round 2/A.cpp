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

#define SZ 101

int dp[SZ][SZ][SZ][SZ][4];
//char col[SZ][SZ][SZ][SZ][4];
int now;

int solve(int zero, int one, int two, int three, int k, int& p) {
    if (zero + one + two + three == 0) return 0;
    int &ret = dp[zero][one][two][three][k];
    if (ret != -1) return ret;
//    if (col[zero][one][two][three][k] == now) return ret;
//    col[zero][one][two][three][k] = now;
    ret = (k == 0);
    if (zero) ret = (k == 0) + solve(zero - 1, one, two, three, k, p);
    if (one) ret = max(ret, (k == 0) + solve(zero, one - 1, two, three, (k + 1) % p, p));
    if (two) ret = max(ret, (k == 0) + solve(zero, one , two - 1, three, (k + 2) % p, p));
    if (three) ret = max(ret, (k == 0) + solve(zero, one, two, three - 1, (k + 3) % p, p));
    return ret;
}

int main() {
//    #if defined JESI
        freopen("A-large.in", "r", stdin);
        freopen("2.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, p;
        cin >> n >> p;

        vector <int> cnt(10, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x % p]++;
        }
        mem(dp, -1);
        cout << "Case #" << cs + 1 << ": " << solve(cnt[0], cnt[1], cnt[2], cnt[3], 0, p) << endl;
    }

    return 0;
}






