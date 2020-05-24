#include "stdio.h"
#include "vector"
#include "string.h"
#include "iostream"

using namespace std;

#define SZ 610

int par[SZ*SZ];
char col[SZ*SZ];
char arr[SZ][SZ];
int mark[SZ][SZ];

vector <int> adj[SZ*SZ];

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

bool dfs(int u)
{
    int i, j, k;

    if(col[u])
        return false;
    k = adj[u].size();

    for(i=0; i<k; i++)
    {
        j = adj[u][i];
        if(!col[j])
        {
            col[j] = 1;
            if(par[j] == -1 || dfs(par[j]))
            {
                par[j] = u;
                return true;
            }
        }
    }

    return false;
}


int bpm(int n)
{
    int i, j, ret = 0;

    memset(par, -1, sizeof(int)*(n+2));

    for(i=0; i<n; i++)
    {
        memset(col, 0, sizeof(char)*(n+2));

        if(dfs(i))
            ret++;
    }

    return ret;
}


int main()
{
    int test = 0;
    int t, n, i, j, k, cnt, u, v;

    scanf("%d",&t);

    while(t--)
    {
        cnt = 0;
        scanf("%d",&n);

        for(i=0;i<=n*n;i++)
            adj[i].clear();

        for(i=0; i<n; i++)
        {
            scanf("%s",arr[i]);
            for(j=0; j<n; j++)
            {
                if(arr[i][j] == '#')
                    mark[i][j] = cnt++;
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j] == '#')
                {
                    for(k=0;k<4;k++)
                    {
                        u = i + x[k];
                        v = j + y[k];
                        if(u >= 0 && v>= 0 && u < n && v < n && arr[u][v] == '#')
                        {
                            adj[ mark[i][j] ].push_back( mark[u][v] );
                            adj[ mark[u][v] ].push_back( mark[i][j] );
                        }
                    }
                }
            }
        }

        printf("Case %d: %d\n",++test, bpm(cnt)/2);
    }

    return 0;
}
