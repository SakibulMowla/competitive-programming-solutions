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

template <class T> T GCD(T a,T b)
{
    if(b == 0) return a;
    return GCD(b,a%b);
}

template <class T> T LCM(T a,T b)
{
    return (a*b) / GCD(a,b);
}

typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

ll arr[15];

//%I64d
int main()
{
    ll i,j,k,n,t;
    cin >> t;
    printf("Lumberjacks:\n");
    while(t--)
    {
        for(i=0;i<10;i++) cin >> arr[i];
//        j = k = 0;
        for(i=1;i<10;i++)
            if(arr[i] > arr[i-1])
                break;
        if(i == 10)
        {
            printf("Ordered\n");
            continue;
        }
        for(i=1;i<10;i++)
            if(arr[i] < arr[i-1])
                break;
        if(i == 10)
        {
            printf("Ordered\n");
            continue;
        }
        printf("Unordered\n");
    }

    return 0;
}
