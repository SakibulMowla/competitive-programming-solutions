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

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

typedef long long ll;
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
ll bigmod(ll a,ll b,ll m)
{
    if(b == 0) return 1%m;
    ll x = bigmod(a,b/2,m);
    x = (x * x) % m;
    if(b % 2 == 1) x = (x * a) % m;
    return x;
}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1000000007LL;

//%I64d
int main()
{
    ll n,m,r,i,j,k,l,ans,len;

    string s;

    while(cin >> s >> k)
    {
        len = sz(s);
        if(k > 1)
        {
            j = len * k;
            r = bigmod(2LL, j, mod) - 1;
            if(r < 0) r += mod;
            j = bigmod(2LL, len, mod) - 1;
            if(j < 0 ) j += mod;
            r = (r * bigmod(j, mod-2, mod)) % mod;
        }
        ans = 0LL;
        for(i=0; i<len; i++)
        {
            if(s[i] == '0' || s[i] == '5')
            {
                ans = (ans + bigmod(2LL, i, mod)) % mod;
            }
        }
        if(k > 1)
        {
            ans = (ans * r) % mod;
        }
        cout << ans << endl;
    }

    return 0;
}
