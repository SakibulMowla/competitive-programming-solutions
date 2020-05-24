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
const int inf = 1E9;
const ll mod = 1E9+7LL;

#define SZ  110

ll fact[SZ];
ll inv[SZ];
int cnt[12];
ll dp[12][12][110];
int col[12][12][110];
int now;
int N, N2;

ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

void pre () {
    fact[0] = 1LL;
    inv[0] = 1LL;
    for (int i = 1; i <= 100; i++) {
        fact[i] = ((ll)i * fact[i-1]) % mod;
        inv[i] = BigMod(fact[i], mod-2, mod);
    }
    return;
}

inline int calc (int i, int digit, int sum) {
    return (((sum + (i * digit)) % 11) + 11) % 11;
}

ll solve (int digit, int sum, int alt) { /// current digit, sum in modulo 11, count of alternating digits
    ll &ret = dp[digit][sum][alt];
    if (col[digit][sum][alt] == now) return ret;

    col[digit][sum][alt] = now;
    if (alt > N) return ret = 0LL;

    if (digit == 10) {
        if (alt == N && sum == 0) return ret = (fact[N-1] * fact[N2]) % mod;
        return ret = 0LL;
    }

    ret = 0LL;
    if (!cnt[digit]) return ret = solve(digit+1, sum, alt);

    for (int i = 0; i <= cnt[digit]; i++) {
        ll tmp = (solve(digit+1, calc(i-(cnt[digit]-i), digit, sum), alt+i) * inv[i]) % mod;
        tmp = (tmp * inv[ cnt[digit]-i ]) % mod;
        ret = (ret + tmp) % mod;
    }

    return ret;
}

ll solve () {
    ll ans = 0LL;
    for (int i = 1; i < 10; i++) {
        if (cnt[i]) {
            cnt[i]--;
            now++;
            ans = (ans + solve(0, i, 1)) % mod;
            cnt[i]++;
        }
    }
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    pre();
    string s;

    while (cin >> s) {
        while (s[0] == '0') s.erase(0, 1);
        N = sz(s)/2 + (sz(s)%2);
        N2 = sz(s) - N;

        mem(cnt, 0);
        for (int i = 0; i < sz(s); i++)
            cnt[ s[i]-'0' ]++;

        cout << solve() << '\n';
    }

    return 0;
}


