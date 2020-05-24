#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 1000+10

ll f[SZ];
ll ff[SZ];
ll dp[SZ][110][2];
ll n, k, m;


ll solve (int pos, ll kval, int pre) {
    ll &ret = dp[pos][kval][pre];
    if (ret != -1) {
        return ret;
    }
    if (pos == 0) {
        return (kval == 0 && pre);
    }
    if (pos != n && kval == 0 && pre) {
        return (9LL * f[pos-1]) % m;
    }

    ret = 0LL;
    int st = (pos == 1? 1 : 0);

    for (int i = st; i < 10; i++) {
        ret = (ret + solve(pos - 1, ((ll)i * ff[n-pos] + kval) % k, pre || (i != 0))) % m;
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    scanf("%I64d %I64d %I64d", &n, &k, &m);

    f[0] = 1 % m;
    ff[0] = 1 % k;
    for (int i = 1; i <= n; i++) {
        f[i] = (10LL * f[i-1]) % m;
        ff[i] = (10LL * ff[i-1]) % k;
    }

    mem(dp, -1);
    printf("%I64d\n", solve(n, 0, 0));

    return 0;
}






