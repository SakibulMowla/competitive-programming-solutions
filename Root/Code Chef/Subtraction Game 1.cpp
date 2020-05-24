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
template <class T> T gcd(T a, T b)
{
    while(b == 0) return a;
    return gcd(b,a%b);
}
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
    ll t,n,m,i,j,k;
    vector <ll> arr;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);

        arr.clear();

        for(i=0; i<n; i++)
        {
            scanf("%lld",&j);
            arr.push_back(j);
        }

        sort(arr.begin(),arr.end());

        if(arr[0] == arr[n-1])
            printf("%lld\n",arr[0]);
        else
        {
            j = arr[0];
            for(i=1;i<=n;i++)
                j = gcd(j,arr[i]);
            printf("%lld\n",j);
        }

    }

    return 0;
}
