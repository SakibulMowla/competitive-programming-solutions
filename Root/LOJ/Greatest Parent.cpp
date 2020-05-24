#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
using namespace std;
#define SZ 100100

typedef long long ll;

ll n , col[SZ] , val[SZ] , L[SZ] , P[SZ][20];
vector <ll> input[SZ];

void DFS(ll source)
{
    col[source] = 1;
    ll i,j,k;
    k = input[source].size();
    for(i=0;i<k;i++)
    {
        j = input[source][i];
        if(col[j] == 0)
        {
            L[j] = L[source] + 1;
            P[j][0] = source;
            DFS(j);
        }
    }
}

void process()
{
    ll i,j,h,lev;

    for(i=0;i<=n;i++)
        for(j=0;j<20;j++)
            P[i][j] = -1;

    val[0] = 1;
    L[0] = 0;

    for(i=0;i<=n;i++) col[i] = 0;
    DFS(0);

    for(h=1LL;(1LL<<h)<n;h++);--h;

    for(lev=1;lev<=h;lev++)
        for(i=0;i<n;i++)
            if(P[i][lev-1] != -1)
                P[i][lev] = P[ P[i][lev-1] ][lev-1] /*, printf("P[%lld][%lld] = %lld\n",i,lev,P[i][lev])*/;
}

ll query(ll a,ll price)
{
    ll i,h;
    for(h=1;(1LL<<h)<n;h++);--h;
    for(i=h;i>=0;i--)
    {
        if(P[a][i] != -1 && val[ P[a][i] ] >= price)
            /*printf("P[%lld][%lld] = %lld val[%lld] = %lld\n",a,i,P[a][i],P[a][i],val[P[a][i]]) ,*/ a = P[a][i];
    }
    return a;
}

int main()
{
//    freopen("1.txt","r",stdin);
    ll t=0,test,i,j,k,q;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&q);
        for(i=0;i<=n;i++) input[i].clear();
        for(i=1;i<n;i++)
        {
            scanf("%lld %lld",&j,&k);
            val[i] = k;
            input[j].push_back(i);
        }
        process();
        printf("Case %lld:\n",++t);
        while(q--)
        {
            scanf("%lld %lld",&j,&k);
            printf("%lld\n",query(j,k));
        }
    }

    return 0;
}
