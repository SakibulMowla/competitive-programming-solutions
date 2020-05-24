#include "stdio.h"
#include "string.h"

#define SZ 10000001
typedef unsigned long long ll;

ll bigmod(ll a,ll p,ll m)
{
    if(p == 0) return 1ll;
    ll x = bigmod(a,p/2,m);
    x = (x * x) % m;
    if(p % 2) x = (a * x) % m;
    return x;
}

//ll arr[SZ],gen[SZ];
const ll mod = 1000000007;

int main()
{
    ll i,j,k,n,t,pre;
//    pre = 1;
//    k = 0;
//    for(i=0; i<SZ; i++)
//    {
//        if(i%2 == 0)
//            pre = (pre * 26) % mod;
//        k = (k + pre) % mod;
//        arr[i] = k;
//        gen[i] = pre;
//    }
    while(scanf("%llu",&t)==1)
    {
        while(t--)
        {
            scanf("%llu",&n);
            j = (n / 2);
            k = (( bigmod(26ll,j+1,mod)  ) - 1ll) % mod ;
            printf("k = %llu\n",k);
            k = (k + k) % mod;
            printf("k = %llu\n",k);
            if(n % 2 == 1) k = (k + bigmod(26ll,j+1,mod) ) % mod;
            printf("%llu\n",k);
        }
    }

    return 0;
}
