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
#define SZ 2000100

bool comp(ll a,ll b)
{
    return a > b;
}

ll cnt[SZ];
ll arr[SZ];

//%I64d
int main()
{
    ll n, m, i, sum;

    while(scanf("%I64d", &n) == 1)
    {
        for(i=1;i<=n;i++)
            scanf("%I64d", &arr[i]);

        sort(arr+1,arr+n+1,comp);

        for(i=1;i<=n;i++)
            cnt[i] = cnt[i-1] + arr[i] ;

        m = 1;
        sum = 0;

        while(m <= n)
        {
            sum += cnt[m];
            m *= 4;
        }

        cout <<sum << "\n";
    }

    return 0;
}
