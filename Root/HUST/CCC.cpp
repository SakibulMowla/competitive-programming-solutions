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

int x[] = {0,0,-1,1};//4-way
int y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 15
const int inf = 1e9;
const ll mod = 1LL;

char grid[SZ][SZ];
int r, c;
int hx, hy;

vector <pii> food;

int fdist[SZ][SZ][SZ][SZ];
bool col[SZ][SZ];

queue <int> Q;

void bfs(int sx, int sy)
{
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            fdist[sx][sx][i][j] = inf;



    fdist[sx][sy][sx][sy] = 0;



    while(!Q.empty()) Q.pop();

    Q.push(sx);
    Q.push(sy);

    int i, j, k, u, v, a, b;

    for(i=0; i<15; i++)
        for(j=0; j<15; j++)
            col[i][j] = 0;

    col[sx][sy] = 1;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        v = Q.front();
        Q.pop();

        for(i=0; i<4; i++)
        {
            a = u + x[i];
            b = v + y[i];

            if(a >= 0 && b >= 0 && a < r && b < c && grid[a][b] != '#' && col[a][b] == 0)
            {
//                if(sx == 0 && sy == 0)
//                    printf("ab %d %d\n",a,b);
                col[a][b] = 1;
                fdist[sx][sy][a][b] = fdist[sx][sy][u][v] + 1;
                Q.push(a);
                Q.push(b);
            }
        }
    }
}


int dp[SZ][(1<<9)+10];

int glox, gloy;


int solve(int now, int mask)
{
    if(!mask)
        return fdist[food[now].X][food[now].Y][glox][gloy];

    int i, &ret = dp[now][mask];
    if(ret != -1)
        return ret;

    ret = inf;

    for(i=1; i<sz(food); i++)
    {
        if(mask&(1<<i))
        {
            ret = min( ret, solve(i, mask&~(1<<i) ) +  fdist[food[now].X][food[now].Y][food[i].X][food[i].Y] );
        }
    }

    return ret;
}




//%I64d
int main()
{

    int test=0, t, i, j, k, ans, ans1, ans2, mask;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&r,&c);

        for(i=0; i<r; i++)
            scanf("%s",grid[i]);

        food.clear();

        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(grid[i][j] == 'H')
                {
                    hx = i, hy = j;
                    food.push_back(MP(i, j));
                }
            }
        }


        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                if(grid[i][j] == 'F')
                    food.push_back(MP(i, j));


        for(i=0; i<sz(food); i++)
        {
//            printf("i = %d\n",i);
            bfs(food[i].X, food[i].Y);
        }

//        bfs(hx, hy);



        mask = 1<<(int)sz(food);
        mask = mask - 1;

//        printf("mask = %d\n",mask);

        ans = inf;

        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                for(k=0; k<=mask; k++)
                {
                    if(grid[i][j] == '#') continue;
                    int res1, res2;
                    mem(dp, -1);
                    glox = i;
                    gloy = j;
                    res1= solve(0, k&~(1));
                    res2= solve(0, (k^mask)&~(1) );
                    ans = min(ans, max( solve(0, k&~(1)), solve(0, (k^mask)&~(1)  ) ) );
                    printf("mask:%d %d %d %d %d %d\n", mask, res1, res2, i, j, ans);
                }

//        printf("%d\n",fdist[0][0][1][2]);
        printf("ans = %d\n",ans);
        if(ans >= inf)
            printf("Case %d: -1\n",++test);
        else
            printf("Case %d: %d\n",++test, ans);
    }


    return 0;
}

















