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

template <class T> T GCD(T a,T b)
{
    if(b == 0) return a;
    return GCD(b,a%b);
}

template <class T> T LCM(T a,T b)
{
    return (a*b) / GCD(a,b);
}

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

//%I64d
int main()
{
    ll  a,b,c,d,p,q,r,s,test,t=0,i,j,k;
    cin >> test;
    while(test--)
    {
        scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
        scanf("%lld.%lld.%lld.%lld",&p,&q,&r,&s);
        i = 0;
        j = 0;
        while(p)
        {
            if(p%10) j += pow(2,i);
            i++;
            p /= 10;
        }
        if(j != a)
        {
            printf("Case %lld: No\n",++t);
            continue;
        }

        i = 0;
        j = 0;
        while(q)
        {
            if(q%10) j += pow(2,i);
            i++;
            q /= 10;
        }
        if(j != b)
        {
            printf("Case %lld: No\n",++t);
            continue;
        }

        i = 0;
        j = 0;
        while(r)
        {
            if(r%10) j += pow(2,i);
            i++;
            r /= 10;
        }
        if(j != c)
        {
            printf("Case %lld: No\n",++t);
            continue;
        }

        i = 0;
        j = 0;
        while(s)
        {
            if(s%10) j += pow(2,i);
            i++;
            s /= 10;
        }
        if(j != d)
        {
            printf("Case %lld: No\n",++t);
            continue;
        }
        printf("Case %lld: Yes\n",++t);
    }

    return 0;
}
