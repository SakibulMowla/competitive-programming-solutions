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

char arr[6][6];

int check(int n,int m)
{
    int i,j,k;
    i= j = 0;
    if(arr[n][m] == '#') i++;
    else j++;
    if(arr[n][m+1] == '#') i++;
    else j++;
    if(arr[n+1][m] == '#') i++;
    else j++;
    if(arr[n+1][m+1] == '#') i++;
    else j++;
    if(i >= 3 || j >= 3) return 1;
    return 0;
}

//%I64d
int main()
{
    ll i,j,k,n,m;

    while(cin >> arr[0])
    {
        k = 0;
        for(i=1;i<4;i++)
            cin >> arr[i];
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(check(i,j))
                        k = 1;
            }
        }
        if(k) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
