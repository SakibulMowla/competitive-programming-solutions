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
#define SZ 10010

ll dp[SZ];
vector <ll> input[SZ];

ll solve(ll n,ll val)
{
    ll &ret = dp[n];
    if(ret != -1) return ret + val;
    ll i,j,k;
    ret = val;
    k = input[n].size();
    for(i=0;i<k;i++)
    {
        ret += solve(input[n][i] , 1LL);
    }
    return ret;
}

//%I64d
int main()
{
    ll i,j,k,n,m,cnt;
    while(cin >> n >> m)
    {
        for(i=0;i<=n;i++)
            input[i].clear() , dp[i] = -1;
        for(i=0;i<n;i++)
        {
            cin >> j >> k;
            input[k].push_back(j);
        }
        cnt = 0;
        for(i=1;i<=n;i++)
        {
            if(solve(i,0LL) == n-1)
                cnt++;
            cout << "solve = " << solve(i,0LL) << "\n";
        }
        cout << cnt << "\n";
    }


    return 0;
}
