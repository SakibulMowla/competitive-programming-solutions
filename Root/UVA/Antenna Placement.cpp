#include "stdio.h"
#include "string.h"
#include "map"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 45
#define mp(a,b) make_pair(a,b)

typedef pair <int , int> pii;
map <pii , int> M;

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

char arr[SZ][SZ];
int par[SZ*SZ];
bool col[SZ*SZ];
vector <int> adj[SZ*SZ];

bool DFS(int u)
{
    if(col[u]) return false;
    int i,k,v;
    k = adj[u].size();
    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(col[v] == 0)
        {
            col[v] = 1;
            if(par[v] == -1 || DFS(par[v]))
            {
                par[v] = u;
                return true;
            }
        }
    }
    return false;
}

int BPM(int n)
{
    int i,j,ret=0;
    for(i=0; i<n; i++) par[i] = -1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++) col[j] = 0;
        if(DFS(i)) ret++;
    }
    return ret;
}

int main()
{
    int t,n,m,i,j,k,u,v,tot,MM,cnt;
    scanf("%d",&t);
    while(t--)
    {
        tot = cnt = 0;
        M.clear();
        scanf("%d %d",&n,&m);
        for(i=0; i<n; i++)
            scanf("%s",arr[i]);
        for(i=0; i<=n*n; i++)
            adj[i].clear();
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(arr[i][j] == '*')
                {
                    cnt++;
                    for(k=0; k<4; k++)
                    {
                        u = i + x[k];
                        v = j + y[k];
                        if(u >= 0 && v >= 0 && u < n && v < m && arr[u][v] == '*')
                        {
                            if(M.find(mp(i,j)) == M.end()) M[mp(i,j)] = tot++;
                            if(M.find(mp(u,v)) == M.end()) M[mp(u,v)] = tot++;
                            adj[M[mp(i,j)]].push_back(M[mp(u,v)]);
                        }
                    }
                }
            }
        }

//        printf("cnt = %d  t = %d\n",cnt,tot);

        MM = BPM(tot);
        printf("%d\n",cnt-(MM/2));
    }

    return 0;
}
