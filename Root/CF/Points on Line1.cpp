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

ll bigmod(ll a,ll b,ll m)
{
    if(b == 0) return 1%m;
    ll x = bigmod(a,b/2,m);
    x = (x * x) % m;
    if(b % 2 == 1) x = (x * a) % m;
    return x;
}
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
#define SZ 1000010

ll arr[SZ];

//%I64d
int main()
{
    ll n,d,i,j,k,prej;

    while(cin >> n >> d)
    {
        for(i=0;i<n;i++)
            cin >> arr[i];
        if(n <= 2)
        {
            printf("0\n");
            continue;
        }

        i = k = prej =  0;
        j = 2;

        while(i < n && j < n)
        {
            for(;j<n;j++)
            {
                if(arr[j] - arr[i] > d) break;
                k += ( (j-i)*(j-i-1) ) / 2;
            }

            i++;
        }

        cout << k << "\n";
    }

    return 0;
}
