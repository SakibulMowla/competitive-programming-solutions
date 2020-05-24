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
//
//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//
template <class T> T gcd(T a, T b)
{
    while(b==0) return a;
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

ll sum1,sum2;

void sum(ll a,ll b,ll c)
{
    sum1 = (a*c) + b;
    sum2 = c;
    ll n = gcd(sum1,sum2);

    sum1 /= n;
    sum2 /= n;
}

ll arr[110];

//%I64d
int main()
{
    ll n,m,p,q,i,j,a,b,c;

    while(cin >> p >> q)
    {
        i = gcd(p,q);

        p /= i;
        q /= i;

        cin >> n;

        for(i=1; i<=n; i++)
        {
            cin >> arr[i];
        }

        if(n == 1)
        {
            if(arr[1] == p and 1LL == q)
                printf("YES\n");
            else printf("NO\n");
            return 0;
        }

        a = arr[1];
        b = 1;
        c = arr[n];

        for(i=n-1; i>=1; i--)
        {
            if(i != n-1)
            {
                swap(b,c);
            }

            a = arr[i];
            sum(a,b,c);

            b = sum1;
            c = sum2;
        }

        if(b == p and c == q)
            printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
