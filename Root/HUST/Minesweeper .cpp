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
ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

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
#define SZ 110

//bool col[SZ][SZ];
ll adj[SZ][SZ];
char arr[SZ][SZ];
ll r,c;

void dfs(int p,int q)
{
//    col[p][q] = 1;
    ll i,u,v;
    for(i=0;i<8;i++)
    {
        u = p + x[i];
        v = q + y[i];
        if(u >= 0 && v >= 0 && u < r && v < c)
            adj[u][v]++;
    }
}

//%I64d
int main()
{
    ll i,j,k,n,m,t=0;
    while(cin >> r >> c && (r + c))
    {
        if(t) printf("\n");
        printf("Field #%lld:\n",++t);
        for(i=0;i<r;i++)
            cin >> arr[i];
        memset(adj,0,sizeof(adj));
//        memset(col,0,sizeof(col));
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j] == '*')
                {
                    dfs(i,j);
                }
            }
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j] == '*')
                {
                    printf("*");
                }
                else
                    printf("%d",adj[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
