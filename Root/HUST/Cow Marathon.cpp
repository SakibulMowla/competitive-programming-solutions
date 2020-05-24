#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

using namespace std;

#define MP(a, b) make_pair(a, b)
#define X first
#define Y second
#define SZ 100010
typedef pair <int , int> pii;

bool col[SZ];
vector <pii> adj[SZ];

pii dfs(int u)
{
    col[u] = 1;

    int i, j, k, v;
    pii ret, tmp;

    ret = MP(u, 0);
    k = adj[u].size();

    for(i=0; i<k; i++)
    {
        v = adj[u][i].X;
        j = adj[u][i].Y;
        if(col[v]) continue;
//        printf("%d %d %d\n",u,v,j);
        tmp = dfs(v);
        if(tmp.Y + j > ret.Y)
        {
            ret.X = tmp.X;
            ret.Y = tmp.Y + j;
        }
    }
    return ret;
}


int main()
{
    int n, m, i, j, k, l;
    char ch;

    scanf("%d %d",&n,&m);

    for(i=0; i<m; i++)
    {
        scanf("%d %d %d %c",&j,&k,&l,&ch);
        adj[j].push_back(MP(k, l));
        adj[k].push_back(MP(j, l));
    }

    k = dfs(1).X;

    memset(col, 0, sizeof(col));

    printf("%d\n",dfs(k).Y);

    return 0;
}
