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

/*ll bigmod(ll a,ll b,ll m)
{
    if(b == 0) return 1%m;
    ll x = bigmod(a,b/2,m);
    x = (x * x) % m;
    if(b % 2 == 1) x = (x * a) % m;
    return x;
}*/

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 100010
ll arr[SZ];
//%I64d
int main()
{
    ll n,t,i,ans,sum,b,e;
    while(scanf("%I64d  %I64d",&n,&t) == 2)
    {
        for(i=1;i<=n;i++) scanf("%I64d",&arr[i]);
        b = e = n;
        sum = ans = 0;
        while(b>=1 && e>=1)
        {
            if(sum + arr[b] <= t)
                sum += arr[b] , b--;
            else
                sum -= arr[e] , e--;
            ans = max(ans,e-b);
        }
        printf("%I64d\n",ans);
    }

    return 0;
}
