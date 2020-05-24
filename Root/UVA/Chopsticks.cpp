using namespace  std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "stdlib.h"
#include "math.h"
#include "map"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "iostream"
#include "algorithm"

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

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
#define SZ1 5010
const ll inf = 1e15;
const ll mod = 1LL;

ll arr[SZ1];
ll dp[SZ][SZ1];

ll solve(ll k, ll n, ll thrd)
{
    if(k <= 0) return 0;
    ll &ret = dp[k][n];

    if(ret != -1) return ret;
    ret = inf;

    if(thrd > 0)
        ret = (arr[n] - arr[n-1]) * (arr[n] - arr[n-1]) + solve(k-1, n-2, thrd-1);
    if(n > 2*k) ret = min(ret, solve(k, n-1, thrd+1));

    return ret;
}

//%I64d
int main()
{
    ll n, k, t, i, j;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&k,&n);
        k += 8;

        for(i=0; i<=k; i++)
            for(j=0; j<=n; j++)
                dp[i][j] = -1;

        for(i=1; i<=n; i++)   scanf("%lld",&arr[i]);

        printf("%lld\n", solve(k, n, 0));
    }

    return 0;
}
