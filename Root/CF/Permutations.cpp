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

char arr[10][10] , tmp[10][10];

//%I64d
int main()
{
    ll n, m, i, j, k, minim, high, low;
    int s[10];

    while(cin >> n >> m)
    {
        for(i=0;i<n;i++)    scanf("%s",arr[i]);
        for(i=0;i<m;i++)    s[i] = i;

        minim = 1<<28;

        do
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                    tmp[i][j] = arr[i][ s[j] ];
                tmp[i][j] = '\0';
            }

            high = 0;
            low = 1<<28;

            for(i=0;i<n;i++)
            {
                k = atol(tmp[i]);
                high = max(high, k);
                low = min(low, k);
            }

            minim = min(minim, high - low);

        } while(next_permutation(s,s+m));

        printf("%I64d\n", minim);
    }

    return 0;
}
