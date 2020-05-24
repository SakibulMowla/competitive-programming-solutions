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

#define SZ 22
#define SZ1 42
const ll inf = 1LL<<28;
const ll mod = 1LL;

int x[] = {0,1};
int y[] = {1,0};

int dp[SZ][SZ][SZ1][SZ1][2];
int n;
char arr[SZ][SZ];

int solve(int row, int col, int a, int b, int p)
{
    if(arr[row][col] == 'a')a++;
    else if(arr[row][col] == 'b')b++;

    if(row == n-1 && col == n-1)
    {
//        printf("a = %d b = %d\n",a,b);
        if(a > b)
            return 0;
        else if(a == b)
            return 1;
        return 2;
    }

    int &ret = dp[row][col][a][b][p];
    if(ret != -1) return ret;

    if(p == 0) ret = 0;
    else ret = 2;

    int i, u, v;

    for(i=0;i<2;i++)
    {
        u = row + x[i];
        v = col + y[i];

        if(u < n && v < n)
        {
            if(p == 0) ret = max(ret, solve(u, v, a, b, !p));
            else if(p == 1) ret = min(ret, solve(u, v, a, b, !p));
        }
    }

    return ret;
}

//%I64d
int main()
{
    int i, j, k, l;

    while(scanf("%d",&n) == 1)
    {
        for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
        for(k=0;k<=2*n;k++)
        for(l=0;l<=2*n;l++)
            dp[i][j][k][l][0] = dp[i][j][k][l][1] = -1;

        for(i=0;i<n;i++)
            scanf(" %s",arr[i]);

        k = 2;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
//                if((n-1-i)+(n-1-j)+1 >= (2*n - 1))
                {
//                    k = solve(i, j, 0, 0, 0);
        k = min(k, solve(i, j, 0, 0, 0));
                }
            }
        }

        if(k == 0)
            printf("FIRST\n");
        else if(k == 1)
            printf("DRAW\n");
        else
            printf("SECOND\n");
    }



    return 0;
}



