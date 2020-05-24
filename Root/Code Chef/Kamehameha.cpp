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

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

struct data
{
    int x, y;
};

data point[SZ];

map <int , int> xmap, ymap;
int row[SZ], col[SZ];
bool colRow[SZ], colCol[SZ];

//%I64d
int main()
{

    int t, n, i, j, k, x, y, cnt;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        j = k = cnt = 0;
        xmap.clear();
        ymap.clear();
        mem(row, 0);
        mem(col, 0);
        mem(colRow, 0);
        mem(colCol, 0);

        for(i=0; i<n; i++)
        {
            scanf("%d %d",&point[i].x,&point[i].y);

            if(xmap.find(point[i].x) == xmap.end())
                xmap[ point[i].x ] = j++;
            if(ymap.find(point[i].y) == ymap.end())
                ymap[ point[i].y ] = k++;

            row[ xmap[ point[i].x ] ]++;
            col[ ymap[ point[i].y ] ]++;

//            printf("--------------->>>>>> %d %d\n",xmap[ point[i].x ], ymap[ point[i].y ]);
        }

        for(i=0; i<n; i++)
        {
            x = xmap[ point[i].x ];
            y = ymap[ point[i].y ];

//            printf("rowcol %d colcol %d row %d col %d\n",colRow[x],colCol[y], row[x], col[y]);

            if(colRow[x] || colCol[y] || (row[x] > 1 && col[y] > 1))
                continue;

            cnt++;

            if(row[x] > 1)
            {
                colRow[x] = 1;
            }
            else
            {
                colCol[y] = 1;
            }
        }

//        printf("cnt = %d\n",cnt);

        for(i=0;i<n;i++)
        {
            x = xmap[ point[i].x ];
            y = ymap[ point[i].y ];

            if(colRow[x] || colCol[y])
                continue;

            cnt++;

            if(row[x] >= col[y])
            {
                colRow[x] = 1;
            }
            else
            {
                colCol[y] = 1;
            }
        }

        printf("%d\n",cnt);
    }


    return 0;
}

/*
6
1 0
2 0
3 0
1 1
2 2
3 3
*/
