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
#define SZ 1010

//%I64d
int main()
{
    ll i,j,k,n,big;
    while(cin >> n)
    {
        k = big = 0;
        if(n == 0)
        {
            printf("0.0000000000000\n");
            continue;
        }
        for(i=0;i<n;i++) cin >> j , k += j*j;
        printf("%.100lf\n",(double)k/(double)n);
    }
//    i = j = big = 0;
//    while(cin >> n)
//    {
//        j += n;
//        i++;
//        big = n > big ? n : big;
//    }
//    j -= big;
//    if(i-1 == 0)
//    {
//        printf("%.10lf\n",(double)j);
////        continue;
//    }
//    else
//    printf("%.10lf\n",(double)j/(double)(big));

    return 0;
}
