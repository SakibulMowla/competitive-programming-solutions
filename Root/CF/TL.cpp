
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

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

typedef long long ll;
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 110
const ll inf = 1LL<<28;
const ll mod = 1LL;

int n, m;
int arr1[SZ], arr2[SZ];

bool chech(int t)
{
    int i, j, k;

    for(i=0; i<m; i++)
        if(arr2[i] <= t)
            return false;
    k = 0;

    for(i=0; i<n; i++)
    {
        if(arr1[i] > t)
            return false;
        if(2*arr1[i] <= t)
            k = 1;
    }

    return k;
}

//%I64d
int main()
{

    int i, j, k;

    while(scanf("%d %d",&n,&m) == 2)
    {
        for(i=0; i<n; i++)
            scanf("%d",&arr1[i]);
        for(i=0; i<m; i++)
            scanf("%d",&arr2[i]);

        for(i=1; i<=100; i++)
        {
            if(chech(i))
            {
                printf("%d\n",i);
                return 0;
            }
        }

        printf("-1\n");
    }


    return 0;
}