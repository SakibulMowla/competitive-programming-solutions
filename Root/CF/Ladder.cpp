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

ll arr[SZ] , pos[SZ] , neg[SZ];

//%I64d
int main()
{
    ll n,m,i,j,k;
//    while(1)
    {
        scanf("%I64d %I64d",&n,&m);
        for(i=1;i<=n;i++) scanf("%I64d",&arr[i]);
        pos[n] = n;
        for(i=n-1;i>=1;i--)
        {
            pos[i] = i;
            if(arr[i] <= arr[i+1])
                pos[i] = pos[i+1];
        }
        neg[n] = n;
        for(i=n-1;i>=1;i--)
        {
            neg[i] = i;
            if(arr[i] >= arr[i+1])
                neg[i] = neg[i+1];
        }
        while(m--)
        {
            scanf("%I64d %I64d",&j,&k);
            j = pos[j];
            j = neg[j];
            if(j >= k) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}
