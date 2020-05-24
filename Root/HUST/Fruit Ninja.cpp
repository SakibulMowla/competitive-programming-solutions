#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

typedef long long ll;

//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

template <class T> T gcd(T a, T b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
//
//template <class T> T lcm(T a, T b)
//{
//    return (a/gcd(a,b)) * b;
//}

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
const ll mod = 100000007LL;
#define MP(a,b) make_pair(a,b)
#define SZ 100010

ll arr[SZ] , dp1[SZ] , dp2[SZ];

//%I64d
int main()
{
    ll i,j,k,n,m,test,t=0,ans,cnt1,cnt2;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            dp1[i] = dp2[i] = 0LL;
        }
        ans = 0LL;
        for(i=2;i<n;i++)
        {
            cnt1 = cnt2 = 0LL;
            for(j=i-1;j>=1;j--)
            {
                if(arr[j] < arr[i])
                {
                    dp1[i] = cnt1 = dp1[j] + 1;
                    break;
                }
                if(j == 1) dp1[i] = 0LL;
            }

            for(j=i+1;j<=n;j++)
            {
                if(arr[j] < arr[i])
                {
                    dp2[i] = cnt2 = dp2[j] + 1;
                    break;
                }
            }

            ans = (ans + (cnt1 * cnt2)) % mod;
        }

        printf("%lld\n",ans);

    }


    return 0;
}
