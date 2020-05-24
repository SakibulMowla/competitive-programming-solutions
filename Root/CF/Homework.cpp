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
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1LL;

ll arr[SZ];

bool comp(ll a,ll b)
{
    return a > b;
}

//%I64d
int main()
{
    ll n, g, s, free, d, t, ans, i, gd;

    while(cin >> n >> g >> s)
    {
        free = d = gd = 0;

        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        sort(arr,arr+n,comp);

        for(i=0; i<n; i++)
        {
            t = arr[i];
            if(t <= (free + gd*g))
            {
                if(t <= free)
                    free -= t, t = 0;
                else
                    t -= free, free = 0;
                if(t > 0)
                {
                    ans = t / g;
                    if(t % g) ans++;
                    gd -= ans;
                }
            }
            else
            {
                t -= free;
                free = 0;
                if(gd)
                {
                    t -= (gd*g);
                    gd = 0;
                }
                ans = t / (g+s);
                if(t % (g+s) != 0)
                {
                    t -= (ans*(g+s));
                    ans++;
                    if(t <= s)
                    {
                        free += s - t;
                        if(i+1 < n)
                        {
                            if(arr[i+1] < g)
                                arr[i+1] = 0;
                            else arr[i+1] -= g;
                        }
                    }
                    else
                    {
                        if(i+1 < n)
                        {
                            if(t >= g)
                                {t -= g; free += s - t;}
                            else if(arr[i+1] > t)
                            {
                                arr[i+1] -= g;
                                if(arr[i+1] < 0) arr[i+1] = 0;
                                arr[i+1] += t;
                                free += s;
                            }
                            else
                            {
                                free += s;
                            }
                        }
                    }
                }
                d += ans;
            }
        }
        printf("%lld\n",d);
    }

    return 0;
}
