using namespace std;

#include "stdio.h"
#include "vector"
#include "set"
#include "iostream"

#define SZ 100
#define MP(a,b) make_pair(a,b)

typedef pair <int , int> pii;

int T[SZ] , low[SZ] , tym;
vector <int> adj[SZ];
set <pii> myset;
set <pii>::iterator it;

void init(int n)
{
    myset.clear();

    int i;
    for(i=0;i<=n;i++)
    {
        adj[i].clear();
        T[i] = 0;
    }

}

void bridge(int u,int p)
{
    int i,j,k,v;

    T[u] = low[u] = ++tym;
    k = adj[u].size();

    for(i=0;i<k;i++)
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
//    freopen("1.txt","r",stdin);
    int n,m,i,j,k,p,q;

    while(scanf("%d",&n) == 1)
    {


        init(n);

        for(i=0;i<n;i++)
        {
            scanf("%d (%d)",&j,&k);

            for(p=0;p<k;p++)
            {
                scanf("%d",&q);
                adj[j].push_back(q);
            }

        }

        tym = 0;

        for(i=0;i<n;i++)
        {
            if(T[i] == 0)
                bridge(i , -1);
        }

        printf("%d critical links\n",myset.size());

        for(it=myset.begin();it!=myset.end();it++)
            printf("%d - %d\n",it->first,it->second);

        printf("\n");

    }


    return 0;
}
