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

#define X first
#define Y second

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;

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

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

struct data
{
    int x, y, z;
};

data arr[23];

bool check(int a, int b, int c, int d)
{
    return (a <= c && b <= d);
}

int dp[1100][23][23];
int n;


int solve(int mask, int aa, int bb)
{
    if(!mask)
        return 0;

    int &ret = dp[mask][aa][bb];
    if(ret != -1) return ret;

    int i;
    ret = 0;

    for(i=0; i<n; i++)
    {
        if(mask&(1<<i))
        {
            if(check(arr[i].x, arr[i].y, aa, bb))
                ret = max(ret, 1 + solve(mask&~(1<<i), arr[i].x, arr[i].y));
            if(check(arr[i].y, arr[i].x, aa, bb))
                ret = max(ret, 1 + solve(mask&~(1<<i), arr[i].y, arr[i].x));
            if(check(arr[i].y, arr[i].z, aa, bb))
                ret = max(ret, 1+solve(mask&~(1<<i), arr[i].y, arr[i].z));
            if(check(arr[i].z, arr[i].y, aa, bb))
                ret = max(ret, 1+solve(mask&~(1<<i), arr[i].z, arr[i].y));
            if(check(arr[i].x, arr[i].z, aa, bb))
                ret = max(ret, 1+solve(mask&~(1<<i), arr[i].x, arr[i].z));
            if(check(arr[i].z, arr[i].x, aa, bb))
                ret = max(ret, 1+solve(mask&~(1<<i), arr[i].z, arr[i].x));
        }
    }

    return ret;
}


//%I64d
int main()
{

    int test=0, m, i, k, j, l;

    while(scanf("%d",&n) == 1 && n)
    {
        for(i=0; i<n; i++)
            scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].z);

        k = 1<<n;

        for(i=0; i<=k; i++)
            for(j=0; j<=21; j++)
                for(l=0; l<=21; l++)
                    dp[i][j][l] = -1;

        printf("Case %d: %d\n",++test, solve(k-1, 21, 21));
    }


    return 0;
}

















