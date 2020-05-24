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

ll nCr[65][65];

void pre(ll n)
{
    ll i,j;

    for(i=0;i<=n;i++)
        for(j=0;j<=i;j++)
        {
            if(i == j || j == 0) nCr[i][j] = 1;
            else if(j == 1) nCr[i][j] = i;
            else nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
        }
}

//%I64d
int main()
{
    ll b, g, t, i, j, k;

    while(cin >> b >> g >> t)
    {
        pre(max(b,g));s
        k = 0;
        for(i=1;i<=g;i++)
        {
            j = t - i;
            if(j >= 4 && j <= b)
                k += nCr[g][i] * nCr[b][j];
        }

        printf("%I64d\n", k);
    }

    return 0;
}
