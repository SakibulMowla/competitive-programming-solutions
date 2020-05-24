using namespace std;
#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
#define SZ 101000

typedef long long ll;
const ll inf = (1LL<<28);

ll n , col[SZ] , par[SZ][20] , L[SZ] , choto[SZ][20] , boro[SZ][20];
struct data
{
    ll to,cost;
    data(ll p,ll q)
    {
        to = p;
        cost = q;
    }
};
vector <data> edge[SZ];

void dfs(ll source)
{
//    printf("dfs = %lld\n",source);
    col[source] = 1;
    ll i,j,k;
    k = edge[source].size();
    for(i=0; i<k; i++)
    {
        j = edge[source][i].to;
        if(col[j] == 0)
        {
            L[j] = L[source] + 1;
            par[j][0] = source;
            choto[j][0] = edge[source][i].cost;
            boro[j][0] = edge[source][i].cost;
//            printf("par[%lld][0] = %lld\n",j,par[j][0]);
            dfs(j);
        }
    }
}

void process()
{
    ll i,j,lev,h;

    for(h=1; (1<<h)<=n; h++);
    --h;

    for(i=0; i<=n; i++)
        for(j=0; j<=h; j++)
            par[i][j] = -1 , choto[i][j] = inf , boro[i][j] = -inf;
    for(i=0; i<=n; i++)
        col[i] = 0;
    L[1] = 0;
    dfs(1);

//    printf("yes\n");
    for(lev=1; lev<=h; lev++)
        for(i=1; i<=n; i++)
            if(par[i][lev-1] != -1)
            {
                choto[i][lev] = min(choto[i][lev-1] , choto[ par[i][lev-1] ][lev-1]);
                boro[i][lev] = max(boro[i][lev-1] , boro[ par[i][lev-1] ][lev-1]);
                par[i][lev] = par[ par[i][lev-1] ][lev-1];
//                printf("i = %lld lev = %lld par = %lld choto = %lld boro = %lld\n",i,lev,par[i][lev],choto[i][lev],boro[i][lev]);
            }
}

ll maxim , minim;

void query(ll p,ll q)
{
    if(L[p] < L[q]) swap(p,q);
    ll i,h;

    for(h=1; (1LL<<h)<=L[p]; h++);
    --h;

    for(i=h; i>=0; i--)
    {
        if(L[p] - (1LL<<i) >= L[q])
        {
            maxim = max(maxim , boro[p][i]);
            minim = min(minim , choto[p][i]);
            p = par[p][i];
        }
    }

    if(p == q) return;

    for(i=h; i>=0; i--)
        if(par[p][i] != -1 && par[q][i] != -1 && par[p][i] != par[q][i])
        {
            maxim = max(maxim , max(boro[p][i] , boro[q][i]) );
            minim = min(minim , min(choto[p][i] , choto[q][i]));
            p = par[p][i];
            q = par[q][i];
//            printf("p = %lld q = %lld i = %lld maxim = %lld mninm = %lldc\n",p,q,i,maxim,minim);
        }
    maxim = max(maxim , max( boro[p][0] , boro[q][0] ) );
    minim = min(minim , min( choto[p][0] , choto[q][0] ) );
    return;
}

int main()
{
//    freopen("1.txt","r",stdin);
    ll t=0,test,i,j,k,m;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        for(i=0; i<=n; i++)
            edge[i].clear();
        for(i=0; i<n-1; i++)
        {
            scanf("%lld %lld %lld",&j,&k,&m);
            edge[j].push_back( data(k,m) );
            edge[k].push_back( data(j,m) );
        }
        process();
        printf("Case %lld:\n",++t);
        scanf("%lld",&k);
        while(k--)
        {
            scanf("%lld %lld",&i,&j);
            maxim = -inf;
            minim = inf;
            query(i,j);
            printf("%lld %lld\n",minim,maxim);
        }
    }
}
