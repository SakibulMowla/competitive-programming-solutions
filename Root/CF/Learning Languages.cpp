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

//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 110

bool check[SZ][SZ] , mark[SZ];
ll n,m;
vector <ll> lang[SZ];
//%I64d

void dfs(int p)
{
    ll i,j,k;
    mark[p] = 1;
    for(i=0; i<lang[p].size(); i++)
    {
        j = lang[p][i];
        for(k=0; k<n; k++)
        {
            if(mark[k] == 0 && check[k][j] == 1)
                dfs(k);
        }
    }
}

int main()
{
    ll i,j,k,l,cnt;

    while(scanf("%I64d %I64d",&n,&m) == 2)
    {
        memset(mark,0,sizeof(mark));
        memset(check,0,sizeof(check));
        for(i=0; i<=n; i++)
            lang[i].clear();
        cnt = 0;
        for(i=0; i<n; i++)
        {
            scanf("%I64d",&j);
            if(j == 0) cnt++;
            for(l=0; l<j; l++)
            {
                scanf("%I64d",&k);
                lang[i].push_back(k);
                check[i][k] = 1;
            }
        }
        if(cnt == n)
        {
            printf("%I64d\n",n);
            continue;
        }
        k = 0;
//        printf("udfs\n");
        for(i=0; i<n; i++)
        {
            if(mark[i] == 0)
            {
                dfs(i);
                k++;
            }
        }
        printf("%I64d\n",--k);
    }

    return 0;
}
