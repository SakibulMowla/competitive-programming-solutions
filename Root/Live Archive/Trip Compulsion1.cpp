#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
#define SZ 3010

typedef long long ll;
ll par[SZ] , rank[SZ];
const ll inf = 0x7fffffffLL;

struct data
{
    ll x,y,d;
};

vector <data> path;

bool comp(data p,data q)
{
    return p.d < q.d;
}

ll find(ll u)
{
    ll v=u,tmp;
    while(par[v] != v)
        v = par[v];
    while(u!=v)
    {
        tmp = par[u];
        par[u] = v;
        u=tmp;
    }
    return v;
}

void makepar(ll n)
{
    ll i;
    for(i=0; i<n; i++) par[i] = i , rank[i] = 1;
}

void Union(ll a,ll b)
{
    if(rank[a] >= rank[b])
    {
        par[b] = a;
        if(rank[a] == rank[b])
            rank[a]++;
    }
    else
        par[a]=b;
}

int main()
{
    ll t,n,r,s,e,i,j,ans;
    data u;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld %lld %lld",&n,&r,&s,&e);
        path.clear();

        for(i=0; i<r; i++)
        {
            scanf("%lld %lld %lld",&u.x,&u.y,&u.d);
            path.push_back(u);
        }

        sort(path.begin(),path.end(),comp);

        ans = inf;

        for(i=0; i<r; i++)
        {
            makepar(n);

            for(j=i; j<r; j++)
            {
                if(find(path[j].x) != find(path[j].y))
                {
                    Union(find(path[j].x),find(path[j].y));

                    if(find(s) == find(t))
                    {
                        if(path[j].d - path[i].d < ans)
                            ans = path[j].d - path[i].d;
                        break;
                    }
                }
            }
        }

        if(ans < inf) printf("%lld\n",ans);
        else printf("NO PATH\n");
    }

    return 0;
}
