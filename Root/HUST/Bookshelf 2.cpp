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
const ll inf = 1LL<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 30

ll arr[SZ];

//%I64d
int main()
{
    ll i,j,k,n,m,h,best,sum,limit;
    while(cin >> n >> h)
    {
        for(i=0; i<n; i++)
            cin >> arr[i];
        limit = (1LL << n);
//        cout << "limit = " << limit << "\n";
        best = inf;
        while(limit--)
        {
            sum = 0;
            for(i=0; i<n; i++)
            {
                if((1LL<<i) & limit)
                    sum += arr[i];
            }
//            cout << sum << " " << best << "\n";
            if(sum >= h && sum - h < best)
                best = sum - h;
        }
        cout << best << "\n";
    }

    return 0;
}
