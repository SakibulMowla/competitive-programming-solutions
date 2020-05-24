#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
#define SZ 50500

typedef long long ll;
struct data
{
    ll x,y,d;
};

ll par[SZ];

//ll find(ll r)
//{
//    ll j=r,tmp;
//    while(j != par[j])
//    {
//        j = par[j];
//    }
//    while(j != r)
//    {
//        tmp = par[r];
//        par[r] = j;
//        r = tmp;
//    }
//    return j;
//}

ll find(ll r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

bool comp(data p,data q)
{
    return p.d < q.d;
}

vector <data> input;
vector <ll> edge[SZ] , cost[SZ];
ll n , vis[SZ];

void MST()
{
    ll i,j,k,p=0,q;
    for(i=0; i<=n; i++) par[i] = i , vis[i] = 0 , edge[i].clear() , cost[i].clear();
    k = input.size();
    for(i=0; i<k && p < n-1; i++)
    {
        j = find(input[i].x);
        q = find(input[i].y);
        if(j != q)
        {
            p++;
            par[j] = q;
            edge[input[i].x].push_back(input[i].y);
            edge[input[i].y].push_back(input[i].x);
            cost[input[i].x].push_back(input[i].d);
            cost[input[i].y].push_back(input[i].d);
//            printf("%lld %lld dsf,mgbdrskg\n",input[i].x,input[i].y);
        }
    }
}

ll T[SZ] , L[SZ] , D[SZ] , P[SZ][20] , dist[SZ][20];

void DFS(ll source)
{
    ll i,j,k;
    vis[source] = 1;
    k = edge[source].size();
    for(i=0; i<k; i++)
    {
        j = edge[source][i];
        if(vis[j] == 0)
        {
            dist[ j ][0] = cost[source][i];
            P[ j ][0] = source;
            L[j] = L[source] + 1;
            DFS(j);
        }
    }
}

void process()
{
    ll i,j,h,lev;
    for(i=1; i<=n; i++)
        for(j=0; j<20; j++)
            P[i][j] = -1 , dist[i][j] = 0;
    for(h=1LL; (1LL<<h)<=n; h++);
    --h;
    L[1] = 0;
//    printf("yes\n");
    DFS(1);
    for(lev=1; lev<=h; lev++)
        for(i=1; i<=n; i++)
        {
            if(P[i][lev-1] != -1)
            {
                dist[i][lev] = max(dist[i][lev-1] , dist[ P[i][lev-1] ][lev-1]);
                P[i][lev] = P[ P[i][lev-1] ][lev-1];
//                printf("i = %lld lev = %lld dist[i][lvl] = %lld\n",i,lev,dist[i][lev]);
            }
        }
}

ll query(ll a ,ll b)
{
    ll i,h,maxim=0;

    if(L[a] < L[b]) swap(a,b);
    for(h=1; (1LL<<h)<=L[a]; h++);
    --h;

    for(i=h; i>=0; i--)
    {
        if(L[a]-(1LL<<i) >= L[b])
        {
            maxim = max(maxim , dist[a][i]);
            a = P[a][i];
        }
    }
    if(a == b)
        return maxim;

    for(i=h; i>=0; i--)
    {
        if(P[a][i] != -1 && P[b][i] != -1 && P[a][i] != P[b][i])
        {
            maxim = max(maxim , max(dist[a][i] , dist[b][i]));
            a = P[a][i];
            b = P[b][i];
        }
    }

    return max( maxim , max(dist[a][0] , dist[b][0]) );
}

int main()
{
//    freopen("1.txt","r",stdin);
    ll t=0,test,i,j,k,m,q;
    data u;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&m);
        input.clear();
        for(i=0; i<m; i++)
        {
            scanf("%lld %lld %lld",&u.x,&u.y,&u.d);
            input.push_back(u);
        }
        sort(input.begin(),input.end(),comp);
        MST();
        process();
        printf("Case %lld:\n",++t);
        scanf("%lld",&q);
        while(q--)
        {
            scanf("%lld %lld",&j,&k);
            printf("%lld\n",query(j,k));
        }
    }

    return 0;
}
