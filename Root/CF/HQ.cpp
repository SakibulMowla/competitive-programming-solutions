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
    ll i,j,k,n,m,f;
    string str;
    while(cin >> str)
    {
        m = 1;
        i = 1;
        f = 1;
        n = str.size();
        while(i<n && str[i] == str[i-1])
        {
            i++;
            f++;
        }
        for(; i<n; i++)
        {
            j = i + 1;
            k = 1;
            while(j<n && str[j] == str[j-1])
            {
                j++;
                i++;
                k++;
            }
            if(k != f)
            {
                printf("No\n");
                return 0;
            }
        }
        if(f == 1)
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}
