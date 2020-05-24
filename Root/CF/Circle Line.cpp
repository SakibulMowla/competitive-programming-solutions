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

typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

//%I64d
int main()
{
    ll arr[110] ,i,j,k,n,s,t,ans;
    while(scanf("%I64d",&n) == 1)
    {
        for(i=0;i<n;i++) scanf("%I64d",&arr[i]);
        scanf("%I64d %I64d",&s,&t);
        ans = inf;
        i = s-1+n;
        i %= n;
        j = 0;
        while(i != t-1)
        {
            j += arr[i];
            i++;
            i %= n;
        }
        ans = j;
//        printf("%I64d\n",ans);
        i = s-2+n;
        i %= n;
        j = 0;
        while(i != (t-2+n)%n)
        {
//            printf("j = %I64d\n",i);
            j += arr[i];
            i--;
            i += n;
            i %= n;
        }
//        printf("%I64d\n",j);
        if(j < ans) ans = j;
        printf("%I64d\n",ans);
    }

    return 0;
}
