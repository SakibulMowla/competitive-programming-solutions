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

#define SZ 510
const int inf = 1e9;
const ll mod = 1LL;

struct data
{
    int x, y, maxneg, curpow;
    bool operator < (const data &x) const
    {
        return maxneg < x.maxneg;
    }
    data() {}
    data(int a,int b,int c,int d)
    {
        x = a;
        y = b;
        maxneg = c;
        curpow = d;
    }
};

priority_queue <data> pq;

int dist[SZ][SZ], mat[SZ][SZ], tmp[SZ][SZ];
int row, col;

int x[] = {1,0};
int y[] = {0,1};

int dijkstra()
{
    while(!pq.empty()) pq.pop();

    int i, j, k, u, v, a, b, c, d;
    data p;

    for(i=0; i<=row; i++)
        for(j=0; j<=col; j++)
            dist[i][j] = -inf, tmp[i][j] = -inf;

//    printf("yes\n");

    pq.push(data(1, 1, mat[1][1], mat[1][1]));
    dist[1][1] = mat[1][1];
    tmp[1][1] = mat[1][1];

    while(!pq.empty())
    {
        p = pq.top();
        pq.pop();

        a = p.x;
        b = p.y;
        c = p.maxneg;
        d = p.curpow;


        for(i=0;i<2;i++)
        {
            u = a + x[i];
            v = b + y[i];

            if(u >= 1 && v >= 1 && u <= row && v <= col && (dist[u][v] < min(c, d + mat[u][v]) || tmp[u][v] < d + mat[u][v] ) )
            {
                p.x = u;
                p.y = v;
                p.curpow = d + mat[u][v];
                p.maxneg = min(c , d + mat[u][v]);

                dist[u][v] = p.maxneg;
                tmp[u][v] = p.curpow;

                pq.push(p);
            }
        }
    }

    return dist[row][col];
}

//%I64d
int main()
{
   int n, t, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&row,&col);

        for(i=1; i<=row; i++)
            for(j=1; j<=col; j++)
                scanf("%d",&mat[i][j]);

        k = dijkstra();
        k = abs(k) + 1;

        printf("%d\n",k);
    }

    return 0;
}

/*

3 3
0 0 -3
-4 -5 -2
0 0 0
ans = 5

4 4
0 -10 20 -1
-1 -1 -1 -1
-1 -1 -1 -1
-1 -1 -1 0

4 4

0 -2 -6 -99
1 -99 100 -99
1 1 -5 -99
-99 -99 -99 0
ans = 13

*/
