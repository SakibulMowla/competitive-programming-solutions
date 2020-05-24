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

ll dp[4010];
ll n,a,b,c;

ll solve(ll p)
{
//    cout << p << "\n";
    if( p == 0) return 1ll;
    if(p < 0 ) return -inf;
    if(dp[p] != -1) return dp[p];
    dp[p] = -inf;
    if(p > a) dp[p] = max(dp[p],solve(p-a) + 1);
    else dp[p] = max(dp[p],solve(p-a));
    if(p > b) dp[p] = max(dp[p],solve(p-b) + 1);
    else dp[p] = max(dp[p],solve(p-b));
    if(p > c) dp[p] = max(dp[p],solve(p-c) + 1);
    else dp[p] = max(dp[p],solve(p-c));
//    dp[p] = 0;
    return dp[p]; /*= max(dp[p] , max(solve(p-a) , max(solve(p-b) , solve(p-c))) );*/
//    if(p - a >)
}

int main()
{

    while(cin >> n >> a >> b >> c)
    {
        memset(dp,-1,sizeof(dp));
        cout << solve(n) << "\n";
    }

    return 0;
}
