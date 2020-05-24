#include "bits/stdc++.h"
using namespace std;

typedef pair <int , int> pii;

#define SZ 10010
#define sz(a) (int)a.size()
#define MP(a, b) make_pair(a, b)

#define X first
#define Y second

vector <pii> adj[SZ];
bool col[SZ];

int n;

pii dfs(int u)
{
    col[u] = 1;
    pii ret = MP(u, 0);

    int i, j, k;
    pii tmp;
    k = sz(adj[u]);

    for(i=0; i<k; i++)
    {
        j = adj[u][i].X;
        if(col[j]) continue;
        tmp = dfs(j);
        if(tmp.Y + adj[u][i].Y > ret.Y)
            ret = MP(tmp.X, tmp.Y+adj[u][i].Y);
    }
    return ret;
}

void kopa()
{
    int start;

    memset(col, 0, sizeof(bool)*(n+2));
    start = dfs(1).X;

    memset(col, 0, sizeof(bool)*(n+2));
    printf("%d\n",dfs(start).Y);
}

int main()
{
//    freopen("1.txt","r",stdin);
    int m, i, j, k;
    bool blank = false;
    char s[100];

    while(gets(s))
    {
        if(strlen(s) == 0)
        {
            kopa();
            for(i=0; i<=n; i++)
            {
                adj[i].clear();
            }
        }
        else
        {
            sscanf(s,"%d %d %d",&i,&j,&k);
            n = max(n, i);
            n = max(n, j);
            adj[i].push_back(MP(j, k));
            adj[j].push_back(MP(i, k));
        }
    }

    kopa();

    return 0;
}
