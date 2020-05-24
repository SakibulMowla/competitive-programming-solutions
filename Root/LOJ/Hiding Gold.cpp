#include "stdio.h"
#include "string.h"
#include "vector"

#define SZ 405
int par[SZ];
bool col[SZ];
std::vector <int> adj[SZ];
char arr[25][25];

bool dfs(int u)
{
    if(col[u]) return false;

    int i, k, v;
    k = adj[u].size();

    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(!col[v])
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
    int i, ret = 0;
    memset(par, -1, sizeof(int)*(n*m));

    for(i=0; i<n*m; i++)
    {
        memset(col, 0, sizeof(bool)*(n*m));
        if(dfs(i)) ret++;
    }

    return ret;
}

int x[] = {-1,1,0,0};
int y[] = {0,0,1,-1};

int main()
{
    int t=0, test, n, m, i, j, k, u, v, cnt;

    scanf("%d",&test);

    while(test--)
    {
        cnt = 0;
        scanf("%d %d",&n,&m);
        for(i=0; i<n; i++)    scanf("%s",arr[i]);

        for(i=0;i<n*m;i++) adj[i].clear();

        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                if(arr[i][j] == '*')
                {
                    cnt++;
                    for(k=0; k<4; k++)
                    {
                        u = i + x[k];
                        v = j + y[k];
                        if(u >= 0 && v >= 0 && u < n && v < m && arr[u][v] == '*')
                            adj[i*m+j].push_back(u*m+v);
                    }
                }
        k = bpm(n,m);
        k = (k/2) + (cnt-k);
        printf("Case %d: %d\n",++t,k);
    }

    return 0;
}
