#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  110

ll MultMod(ll a,ll b,ll mod){
    a%=mod;
    b%=mod;
    if(b<0) b+=mod;
    if(a<0) a+=mod;
    ll ret=0;
    while(b){
        if(b&1LL){
            ret+=a;
            if(ret>=mod) ret-=mod;
        }
        a=a<<1LL;
        if(a>=mod) a-=mod;
        b=b>>1LL;
    }
    return ret;
}

ll BigMod(ll B,ll P,ll M)
{
    ll R=1LL%M;    /// (B^P)%M
    while(P>0)
    {
        if(P%2LL==1LL)
        {
            R=MultMod(R, B, M);
        }
        P/=2LL;
        B=MultMod(B, B, M);
    }
    return R;
}

ll x, n, m;

ll calc(ll p) {
    if(p == 0) return 1LL;

    ll ans = calc((p-1LL)/2LL);
    ll ans1 = BigMod(x, (p+1LL)/2LL, n) + 1LL;
    if(ans1 >= n) ans1 -= n;
    ans = MultMod(ans, ans1, n);

    if(p%2LL == 0) {
        ans = ans + BigMod(x, p, n);
        if(ans >= n) ans -= n;
    }

    return ans;
}

int main()
{
    #if defined JESI
            freopen("1.txt", "r", stdin);
            freopen("2.txt", "w", stdout);
    #endif

    int t;

    scanf("%d", &t);

    while(t--) {
        scanf("%lld %lld %lld", &x, &m, &n);

        ll ans = calc(m);

        printf("%lld\n", ans);
    }
    return 0;
}







///10000000000000000 10000000000000000 10000000000000000





