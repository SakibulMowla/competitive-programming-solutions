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
const ll mod = 1000000007LL;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

set <char> arr[110];

int main()
{
    ll n,m,i,j,k;
    char str[110];

    while(cin >> n >> m)
    {
        for(i=0;i<n;i++)
            arr[i].clear();

        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            for(j=0;j<m;j++)
                arr[j].insert(str[j]);
        }

        k = 1;

        for(i=0;i<m;i++)
            k = (k * arr[i].size()) % mod;

        printf("%I64d\n", k);
    }

    return 0;
}
