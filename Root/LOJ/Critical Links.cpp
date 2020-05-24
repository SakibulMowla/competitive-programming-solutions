using namespace std;

#include "stdio.h"
#include "string.h"
#include "iostream"
#include "set"
#include "vector"

#define SZ 10100
#define MP(a,b) make_pair(a,b)

typedef pair<int , int> pii;
set <pii> myset;
set <pii>::iterator it;

vector <int> adj[SZ];
int low[SZ] , T[SZ] , tym;

void init(int n)
{
    int i;
    myset.clear();
    for(i=0; i<n; i++)
    {
        T[i] = 0;
        adj[i].clear();
    }
}

void bridge(int u,int p)
{
    int i,j,k,v;
    T[u] = low[u] = tym++;

    k = adj[u].size();

    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(v == p) continue;
        if(T[v] == 0)
        {
            bridge(v,u);
            low[u] = min(low[u] , low[v]);
            if(low[v] > T[u])
            {
                if(u < v)
                    myset.insert(MP(u,v));
                else
                    myset.insert(MP(v,u));
            }
        }
        else if(T[v] < T[u])
            low[u] = min(low[u] , T[v]);
    }
}

int main()
{
    int test=0,t,n,m,i,j,k,p,q;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        init(n);
        for(i=0; i<n; i++)
        {
            scanf("%d (%d)",&j,&p);

            for(k=0; k<p; k++)
            {
                scanf("%d",&q);
                adj[j].push_back(q);
//                adj[q].push_back(j);
            }
        }

        tym = 0;

        for(i=0; i<n; i++)
            if(!T[i])
                bridge(i,-1);

        p = myset.size();

        printf("Case %d:\n%d critical links\n",++test,p);
        for(it=myset.begin(); it!=myset.end(); it++)
            printf("%d - %d\n",it->first,it->second);

    }

    return 0;
}
