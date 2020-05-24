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

ll n,a,b;
map <ll,ll> M;

void dfs(ll now,ll digit)
{
    if(now > n || digit > 10) return;
    if(now != 0) M[now] = 1;
    dfs(now*10+a,digit+1);
    dfs(now*10+b,digit+1);
}

//%I64d
int main()
{
    ll  i,j,k;
    while(cin >> n)
    {
        M.clear();
        for(a=0;a<=9;a++)
            for(b=a+1;b<=9;b++)
                dfs(0,0);
        cout << M.size() << endl;
    }

    return 0;
}
