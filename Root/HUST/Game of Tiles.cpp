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

typedef long long ll;
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

int x[] = {0,0,-1,1};//4-way
int y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 55
const ll inf = 1LL<<28;
const ll mod = 1LL;

int dp[SZ][SZ][7][3];
bool col[SZ][SZ];

// 1 ---> 1
// 0 ---> 2

char arr[SZ][SZ];
int r, c;

int solve(int n,int m,int p1,int p2,int dir,int player)
{
    int &ret = dp[n][m][dir][player];

    if(ret != -1)
        return ret;

    int i, u, v, f = 0;

    if(player == 1) ret = 1;
    else ret = 0;

    for(i=0; i<4; i++)
    {
        u = n + x[i];
        v = m + y[i];
//        printf("n = %d m = %d u = %d v = %d\n",n,m,u,v);
        if(u>=0 && v>=0 && u<r && v<c && arr[u][v] == '.' && !col[u][v] && !(u == p1 && v == p2))
        {
//            printf("yes\n\n");
            f = 1;
            col[u][v] = 1;
            if(player == 1) ret = min(ret, solve(u, v, n, m, i, !player));
            else            ret = max(ret, solve(u, v, n, m, i, !player));
//            col[u][v] = 0;
        }
    }

    if(!f)
    {
//        printf("p = %d %d %d\n",player,n,m);
        if(player == 1) ret = 1;
        else ret = 0;
//        printf("ret = %d\n",ret);
    }

    return ret;
}

//%I64d
int main()
{
//    freopen("1.txt","r",stdin);
    int n, m, i, j, k, ans;

    while(scanf("%d %d",&r,&c) == 2)
    {
        for(i=0; i<r; i++)
        {
            scanf(" %s",arr[i]);
            for(j=0; j<c; j++)
            {
                dp[i][j][0][0] = dp[i][j][1][0] = dp[i][j][2][0] = dp[i][j][3][0] = dp[i][j][4][0] = -1;
                dp[i][j][0][1] = dp[i][j][1][1] = dp[i][j][2][1] = dp[i][j][3][1] = dp[i][j][4][1] = -1;
            }
        }
        ans = 0;
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                if(arr[i][j] == '.')
                {
                    memset(col, 0, sizeof(col));
                    ans = max(ans, solve(i, j, i, j, 4, 1));
//                    printf("-------->>>>>>%d %d solve = %d\n",i,j,solve(i, j, i, j, 4, 1));
                }
//        ans = max(ans, solve(0, 1, 0, 1, 4, 1));
        if(ans == 1) printf("1\n");
        else printf("2\n");
    }

    return 0;
}

/*

3 4
....
XX.X
...X

ans = 2

*/
