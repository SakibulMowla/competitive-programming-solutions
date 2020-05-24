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
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

ll lcs[SZ][SZ];

//%I64d
int main()
{
    ll i,j,k,n,len1,len2;
    string a,b;
    while(cin >> a >> b)
    {
        len1 = a.size();
        len2 = b.size();
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(a[i-1] == b[j-1])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
        cout << lcs[len1][len2] << "\n";
    }

    return 0;
}
