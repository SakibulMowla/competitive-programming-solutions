#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 210

int par[SZ];
bool col[SZ];
vector <int> adj[SZ];

bool dfs(int u)
{
    if(col[u]) return false;
    int i,k,v;
    k = adj[u].size();
    for(i=0; i<k; i++)
    {
        v = adj[u][i];
//        printf("u = %d v = %d\n",u,v);
        if(col[v] == 0)
        {
            col[v] = 1;
            if(par[v] == -1 || dfs(par[v]))
            {
                par[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm(int n,int m)
{
    int i,j,ret=0;
    for(i=0; i<=n+m; i++) par[i] = -1;
//    memset(par,-1,sizeof(par));
    for(i=0; i<n; i++)
    {
        for(j=0; j<=n+m; j++) col[j] = 0;
//        memset(col,0,sizeof(col));
        if(dfs(i)) ret++;
//        printf("i = %d\n",i);
    }
    return ret;
}

int arr1[SZ] , arr2[SZ];

int main()
{
    int i,j,k,n,m,test,t=0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++) scanf("%d",&arr1[i]);
        scanf("%d",&m);
        for(i=0; i<m; i++) scanf("%d",&arr2[i]);

        for(i=0; i<=n+m; i++) adj[i].clear();
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                if(arr2[j] == 0 || ( arr1[i] > 0 && arr2[j] % arr1[i] == 0) )
                    /*printf("%d %d -- %d %d yes\n",i,j+n,arr1[i],arr2[j]) , */adj[i].push_back(j+n);
        printf("Case %d: %d\n",++t,bpm(n,m));
    }

    return 0;
}
