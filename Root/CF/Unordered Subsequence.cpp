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

//%I64d
int main()
{
    ll n, i, j, mn, mx, k;

    while(scanf("%I64d",&n) == 1)
    {
        for(i=1; i<=n; i++)
            scanf("%I64d",&arr[i]);
        mx = mn = 0;
        if(n < 3)
        {
            printf("0\n");
            continue;
        }
        if(arr[1] > arr[2])
        {
            mx =  arr[1];
            j = 1;
            mn = arr[2];
            k = 2;
        }
        else
        {
            mx =  arr[2];
            j = 2;
            mn = arr[1];
            k = 1;
        }
        for(i=3; i<=n; i++)
        {
//            printf("%I64d %I64d\n",mx,mn);
            if(k > j)
            {
                if(arr[j] > arr[k])
                {
                    if(arr[i] > arr[k])
                    {
                        printf("3\n%I64d %I64d %I64d\n",j,k,i);
                        return 0;
                    }
                }
                else if(arr[j] < arr[k])
                {
                    if(arr[i] < arr[k])
                    {
                        printf("3\n%I64d %I64d %I64d\n",j,k,i);
                        return 0;
                    }
                }
            }

            else if(k < j)
            {
                if(arr[k] > arr[j])
                {
                    if(arr[i] > arr[j])
                    {
                        printf("3\n%I64d %I64d %I64d\n",j,k,i);
                        return 0;
                    }
                }
                else if(arr[k] < arr[j])
                {
                    if(arr[i] < arr[j])
                    {
                        printf("3\n%I64d %I64d %I64d\n",j,k,i);
                        return 0;
                    }
                }
            }

            if(arr[i] > mx)
            {
                mx = arr[i];
                j = i;
            }
            if(arr[i] < mn)
            {
                mn = arr[i];
                k = i;
            }
        }
        printf("0\n");
    }

    return 0;
}
