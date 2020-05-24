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

ll arr[100000];
//%I64d
int main()
{
    ll i,j,k,n,m,d,num,ans;

    while(cin >> n >> m >> d)
    {
        num = n * m;
        cin >> arr[0];
        k = arr[0] % d;
        for(i=1;i<num;i++)
        {
            cin >> arr[i];
            if(arr[i] % d != k)
            {
                printf("-1\n");
                return 0;
            }
        }
        ans = 1<<28;
        for(i=0;i<num;i++)
        {
            k = 0;
            for(j=0;j<num;j++)
            {
                k += (abs(arr[i]-arr[j]) / d);
            }
            if(k < ans)
                ans = k;
        }
        cout << ans << "\n";
    }

    return 0;
}
