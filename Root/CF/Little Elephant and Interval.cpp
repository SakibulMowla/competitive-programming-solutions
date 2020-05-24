#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
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
//
//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//
//template <class T> T gcd(T a, T b)
//{
//    while(b == 0) return a;
//    return gcd(b,a%b);
//}
//
//template <class T> T lcm(T a, T b)
//{
//    return (a/gcd(a,b)) * b;
//}

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

char arr[22];
ll len ;
ll dp[20][2][2][2];

ll solve(ll indx,ll flag,ll bos,ll conf)
{
    ll &ret = dp[indx][flag][bos][conf];
    if(ret != -1) return ret;
    if(indx == len-1 && len != 1)
    {
        if(bos == 1)
            return !conf;
        return 10;
    }
    if(indx == len) return ret = 1;

    ll i, lim = arr[indx]-'0';
    if(!flag) lim = 9;
    ret = 0;

    for(i=0; i<lim; i++)
    {
        if(i != 0)
            ret += solve(indx+1, 0, 1, 0);
        else
            ret += solve(indx+1, 0, bos, 0);
    }

    if(indx == 0)
    {
        if(lim <= arr[len-1]-'0')
            ret += solve(indx+1, flag, 1, 0);
        else
            ret += solve(indx+1, flag, 1, 1);
    }
    else
        ret += solve(indx+1, flag, 1, conf);

    return ret;
}

//%I64d
int main()
{
    ll a, b;

    while(cin >> a >> b)
    {
        --a;
        sprintf(arr, "%I64d", a);
        len = strlen(arr);
        memset(dp, -1, sizeof(dp));
        a = solve(0, 1, 0, 1);

        sprintf(arr, "%I64d", b);
        len = strlen(arr);
        memset(dp, -1, sizeof(dp));
        b = solve(0, 1, 0, 1);

        cout << b-a << endl;
    }

    return 0;
}
