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

#define SZ 10000010
const ll inf = 1LL<<28;
const ll mod = 1LL;

int arr[SZ];

//%I64d
int main()
{
    ll n,i,j,k,f,l;
//    freopen("output.txt","w",stdout);
    cin >> n;
//    while(cin >> n)
    {
        k = f = 0;
        l = sqrt(SZ);
        printf("2 ");
        for(i=4;i<SZ;i+=2)
            arr[i] = 1;
        k++;
        for(i=3; i<=10000000; i+=2)
        {
            if(k == n)
                {
                    f = 1;
                    break;
                }
            if(arr[i] == 0)
            {
                printf("%I64d ",i);
                k++;
                if(k == n)
                {
                    f = 1;
                    break;
                }
                for(j=i*i; j<SZ; j+=i+i)
                    arr[j] = 1;
            }
            if(f) break;
        }
        printf("\n");
    }

    return 0;
}

