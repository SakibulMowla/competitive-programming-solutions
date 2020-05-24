#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 1010

bool col[SZ];
int par[SZ];
vector <int> adj[SZ];

bool dfs(int u)
{
    if(col[u]) {/*printf("only u = %d\n",u);*/return false;}
    int i,k,v;
    k = adj[u].size();
    for(i=0;i<k;i++)
    {
        v = adj[u][i];
//        printf("%d %d\n",u,v);
        if(col[v] == 0)
        {
            col[v] = 1;
            if(par[v] == -1 || dfs(par[v]))
            {
//                printf("u = %d   v = %d\n",u,v);
                par[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm(int n,int m)
{
    int i,j,ret = 0;;
    for(i=0;i<=n+m;i++) par[i] = -1;
//    memset(par,-1,sizeof(par));
    for(i=0;i<=n+n;i++)
    {
        for(j=0;j<=n+m;j++) col[j] = 0;
//        memset(col,0,sizeof(col));
        if(dfs(i)){/*printf("%d\n",i);*/ ret++;}
    }
    return ret;
}

int main()
{
    int i,j,n,m,k,test,t=0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<=n+n;i++) adj[i].clear();
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                scanf("%d",&k);
                if(k) adj[i].push_back(j+n);
            }
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",++t,bpm(n,m));
    }

    return 0;
}
