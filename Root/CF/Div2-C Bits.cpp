#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

typedef long long ll;
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

int dp[66][2][2];
ll l, h;

int prep (ll n) {
    int len = 0;
    while(n) {
        len++;
        n >>= 1LL;
    }
    return len;
}

int solve (int pos, int fl, int fh) { ///position, flag low, flag high
    if(pos == -1) return 0;

    int &ret = dp[pos][fl][fh];
    if(ret != -1) return ret;

    ret = 0;
    int lo = fl ? (bool)(l&(1LL<<pos)) : 0;
    int hi = fh ? (bool)(h&(1LL<<pos)) : 1;

    for (int i = lo; i <= hi; i++) {
        int nfl = (fl && i == lo);
        int nfh = (fh && i == hi);
        ret = max(ret, i + solve(pos-1, nfl, nfh));
    }

    return ret;
}

ll num;

void path (int pos, int fl, int fh) {
    if(pos == -1) return;

    int lo = fl ? (bool)(l&(1LL<<pos)) : 0;
    int hi = fh ? (bool)(h&(1LL<<pos)) : 1;

    for (int i = lo; i <= hi; i++) {
        int nfl = (fl && i == lo);
        int nfh = (fh && i == hi);
        if(i + solve(pos-1, nfl, nfh) == solve(pos, fl, fh)) {
            if(i) num |= (1LL<<pos);
            return path(pos-1, nfl, nfh);
        }
    }

    return;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int cs = 0; cs < t; cs++) {
        scanf("%I64d %I64d", &l, &h);
        int len = prep(h);
        mem(dp, -1);
        solve(len, 1, 1);
        num = 0;
        path(len, 1, 1);
        printf("%I64d\n", num);
    }

    return 0;
}


