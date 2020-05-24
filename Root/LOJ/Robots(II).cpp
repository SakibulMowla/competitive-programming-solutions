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

#define SZ 110
const ll inf = 1LL<<28;
const ll mod = 1LL;

int r, c;
bool gar[SZ][SZ];

int dp1[101][101];
ll dp2[101][101][201];

//int cnt;

int solve1(int indx1, int indx2)
{
    if(indx1 > r || indx2 > c)
        return 0;

//    cnt++;

    int &ret = dp1[indx1][indx2];
    if(ret != -1)
        return ret;

    ret = 0;
    ret = gar[indx1][indx2] + max( solve1(indx1+1, indx2), solve1(indx1, indx2+1) );

    return ret;
}

void pathdp(int indx1, int indx2)
{
    if(gar[indx1][indx2] == 1)
    {
        printf(" %d",(c*(indx1-1))+indx2);
    }

    if(indx1+1 <= r && dp1[indx1][indx2] - gar[indx1][indx2] == dp1[indx1+1][indx2])
        return pathdp(indx1+1, indx2);
    else if(indx2+1 <= c && dp1[indx1][indx2] - gar[indx1][indx2] == dp1[indx1][indx2+1])
        return pathdp(indx1, indx2+1);

    return;
}

ll solve2(int indx1, int indx2, int left)
{
    if(left == 0)
        return 1;
    if(indx1 == r || indx2 == c)
        return 0;

    ll &ret = dp2[indx1][indx2][left];
    if(ret != -1)
        return ret;

    int i, j, k;
    ret = 0;

    for(i=indx1;i<=r;i++)
        for(j=indx2;j<=c;j++)
            if(gar[i][j] == 1 /*&& dp1[i][j] == left-1*/)
                ret += solve2(i, j, left-1), ret += solve2(i, j, left);
    return ret;
}

//%I64d
int main()
{

    int n, m, i, j, k, l, x, y, test=0;
    ll ans;

    while(scanf("%d %d",&r,&c) == 2)
    {
        if(r == -1 && c == -1) break;

        for(i=0; i<=r; i++)
            for(j=0; j<=c; j++)
            {
                gar[i][j] = 0;
                dp1[i][j] = -1;
            }

//
        while(scanf("%d %d",&x,&y) == 2)
        {
            if(x == 0 && y == 0) break;
            gar[x][y] = 1;
        }

//        cnt = 0;

//        printf("garbage = %d\n",solve1(1, 1));
        printf("CASE#%d:",++test);
        k = solve1(1, 1);

        for(i=0; i<=r; i++)
            for(j=0; j<=c; j++)
                for(l=0;l<=k;l++)
                    dp2[i][j][l] = -1;



        ans = solve2(1, 1, k);
        printf(" %d %lld",k, ans);
        pathdp(1, 1);
        printf("\n");


//        printf("cnt = %d\n",cnt);
    }


    return 0;
}
















