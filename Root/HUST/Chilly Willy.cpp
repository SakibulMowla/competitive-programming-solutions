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

template <class T> T GCD(T a,T b)
{
    if(b == 0) return a;
    return GCD(b,a%b);
}

template <class T> T LCM(T a,T b)
{
    return (a*b) / GCD(a,b);
}

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

const ll mod = 2 * 3 * 5 * 7;

//%I64d
int main()
{
    ll n,i,j;
    while(cin >> n)
    {
        if(n <= 2)
        {
            printf("-1\n");
            continue;
        }
        if(n == 3)
        {
            printf("210\n");
            continue;
        }
        else
        {
            j = 1;
            for(i=0;i<n-1;i++)
                j = (j * 10) % mod;
            printf("1");
            for(i=0;i<n-4;i++)
                printf("0");
//            cout << "j = " << j << "\n";
            printf("%03lld\n",mod-j);
        }
    }

    return 0;
}
