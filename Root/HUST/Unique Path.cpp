#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 100010

vector <int> adj[SZ];
bool col[SZ] , vis[SZ];
int start[SZ] , st , cnt;

void init(int n)
{
    int i;
    st = 1;
    for(i=0; i<=n; i++)
    {
        adj[i].clear();
        col[i] = 0;
        vis[i] = 0;
        start[i] = 0;
    }
}

int dfs(int n,int par)
{
    start[n] = st++;
    int i,j,k,cycle=0,l,f=0;
    j = adj[n].size();
    for(i=0; i<j; i++)
    {
        k = adj[n][i];
        if(start[k]&&start[k]<start[n])
        {
            if(cycle)
            {
                if(start[k] < start[cycle]&&k!=par)
                    cycle = k;
            }
            else if(k!=par)
                cycle=k;
        }
        else
        {
            l = dfs(k,n);
//           if(n==8)
//            printf(" %d* ", l);
            if(l)
            {
                if(f)
                    f = start[f] > start[l] ? l : f;
                else
                    f = l;
            }
        }
    }
//    if(n==8)
//        printf(" %d %d\n", f, cycle);
    if(f)
    {
        if(start[f]<=start[n])
            col[n] = true;
        if(cycle)
            cycle = start[cycle] < start[f] ? cycle : f;
        else
            cycle = f;
    }
    if(cycle && cycle != par&&start[cycle]<=start[n])
        col[n] = true;
    if(cycle == n) return 0;
    return cycle;
}

void dfs1(int n)
{
    cnt++;
    int i,j,k;
    vis[n] = true;
    j = adj[n].size();
    for(i=0;i<j;i++)
    {
        k = adj[n][i];
        if(vis[k] == 0 && col[k] == 0)
            dfs1(k);
    }
    return;
}

int main()
{
    int n,m,i,j,k,t=0,test,sum;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        init(n);
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        for(i=1; i<=n; i++)
        {
            if(!start[i])
                dfs(i,-1);
        }
//        for(i=1;i<=n;i++)
//            printf("col[%d] = %d start = %d\n",i,col[i],start[i]);
        sum = 0;
        for(i=1;i<=n;i++)
        {
            cnt = 0 ;
            if(vis[i] == 0 && col[i] == 0)
                dfs1(i);
            sum += (cnt * (cnt-1)) / 2;
        }
        printf("Case #%d: %d\n",++t,sum);
    }

    return 0;
}



/*
2
8 10
1 2
2 3
3 4
4 7
7 5
5 6
7 8
4 1
4 2
1 8

13 13
1 2
2 4
4 3
3 10
10 9
5 8
4 5
8 9
8 7
8 6
7 6
11 12
12 13
*/
