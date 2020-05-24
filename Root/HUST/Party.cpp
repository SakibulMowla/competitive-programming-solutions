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
#define SZ 2010

ll par[SZ] , dp[SZ];

ll dfs(ll p)
{
    ll &ret = dp[p];
    if(par[p] == -1)
        return ret = 1;
    if(ret != -1) return ret;
    return ret = dfs(par[p]) + 1;
}

//%I64d
int main()
{
    ll i,j,k,n;
    while(cin >> n)
    {
        memset(par,0,sizeof(par));
        for(i=1;i<=n;i++)
        {
            cin >> j;
            par[i] = j;
        }
        k = 0;
        memset(dp,-1,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            if(dp[i] == -1)
                dfs(i);
            k = max(k , dfs(i));
        }
        cout << k << "\n";
    }

    return 0;
}
