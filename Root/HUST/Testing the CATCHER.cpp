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

template <class T> T gcd(T a, T b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
//
//template <class T> T lcm(T a, T b)
//{
//    return (a/gcd(a,b)) * b;
//}

typedef pair<ll,ll> pii;
const ll inf = 1LL<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 10000000

ll arr[SZ] , tmp[SZ] , L[SZ] , lisseq[SZ];

ll b_search(ll item,ll start,ll end)
{
    ll mid = (start + end) / 2;
    while(start <= end)
    {
        if(tmp[mid] == item)
            return mid;
        if(start == end)
            break;
        if(tmp[mid] > item)
            end = mid;
        else
            start = mid + 1;
        mid = (start + end) / 2;
    }
    return end;
}

ll LIS(ll n)
{
    ll i , start = 0LL , end = n , lis_len =0LL , loc;
    tmp[0] = -inf;
    for(i=1;i<=n;i++)
        tmp[i] = inf;
    for(i=0;i<n;i++)
    {
        loc = b_search(arr[i],start,end);
        tmp[loc] = arr[i];
        lis_len = max(lis_len , loc);
        L[i] = loc;
        end = lis_len + 1;
    }
    return lis_len;
}

//%I64d
int main()
{
    ll n,i,j,item,temp,t=0;
    bool blank = false;
    n = 0;
    while(cin >> item && item != -1)
    {
        if(blank) printf("\n");
        blank = true;
        arr[n++] = item;
        while(cin >> item && item != -1)
        {
            arr[n++] = item;
        }
        for(i=0,j=n-1;i<n/2;i++,j--)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        n = LIS(n);
        printf("Test #%lld:\n",++t);
        printf("  maximum possible interceptions: %lld\n",n);
        n = 0;
    }

    return 0;
}
