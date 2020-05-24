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

//template <class T> T gcd(T a, T b)
//{
//    while(b) b ^= a ^= b ^= a %= b;
//    return a;
//}
//
//template <class T> T lcm(T a, T b)
//{
//    return (a/gcd(a,b)) * b;
//}

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 110

ll t[SZ] , w[SZ] , dp[SZ][2*SZ][2*SZ] , n;

ll solve(ll indx,ll thick,ll width)
{
    if(indx == n)
    {
        if(thick >= width)
            return thick;
        return inf;
    }
    ll &ret = dp[indx][thick][width];
    if(ret != -1) return ret;
    ret = inf;
    ret = min(ret , solve(indx+1,thick+t[indx],width));
    if(width + w[indx] <= 200)
        ret = min(ret , solve(indx+1,thick,width+w[indx]));
    return ret;
}
//%I64d
int main()
{
    ll i,j,k;
    while(cin >> n)
    {
        for(i=0;i<n;i++)
            cin >> t[i] >> w[i];
        memset(dp,-1,sizeof(dp));
        cout << solve(0ll,0ll,0ll) << "\n";
    }

    return 0;
}
