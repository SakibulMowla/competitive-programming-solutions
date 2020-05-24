#include "bits/stdc++.h"

using namespace std;

#define sz(n) (int)n.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define SZ 110

int col[SZ], maincol[SZ];
vector <int> adj[SZ], tmp1, tmp2, ans;
queue <int> Q;

int NOT(int n)
{
    if(n == 1) return 2;
    return 1;
}

void BFS(int node,int rong)
{
    while(!Q.empty()) Q.pop();
    mem(col, 0);

    col[node] = rong;
    Q.push(node);

    int i, u, v, k;

    while(!Q.empty())
    {
        u = Q.front(); Q.pop();
        k = sz(adj[u]);
        for(i=0;i<k;i++)
        {
            v = adj[u][i];
            if(!col[v]) col[v] = NOT(col[u]), Q.push(v);
            if(col[u] == 1 && col[v] == 1) col[v] = 2;
        }
    }
}


int main()
{
    int t, n, m, i, j, k, l;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++)
            adj[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        mem(maincol, 0);
        ans.clear();
        for(l=1;l<=n;l++) if(!maincol[l])
        {
            BFS(l, 1);
            tmp1.clear();
            for(i=1;i<=n;i++) if(col[i] == 1) tmp1.push_back(i);

            BFS(l, 2);
            tmp2.clear();
            for(i=1;i<=n;i++) if(col[i] == 1) tmp2.push_back(i);

            if(sz(tmp1) > sz(tmp2)) {for(i=0;i<sz(tmp1);i++) ans.push_back(tmp1[i]);}
            else                    {for(i=0;i<sz(tmp2);i++) ans.push_back(tmp2[i]);}

            for(i=1;i<=n;i++)
                if(col[i])
                    maincol[i] = 1;
        }
        printf("%d\n",sz(ans));
        for(i=0;i<sz(ans);i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }

    return 0;
}
