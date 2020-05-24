#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <iostream>

#define SZ 30010

using namespace std;

vector<int>edge[SZ];
vector<int>cost[SZ];

int dist[SZ];
bool color[SZ];

int maxi;

void DFS(int m)
{
    int i;

    color[m] = 1;
    for(i=0;i<edge[m].size();i++)
    {
        if(color[edge[m][i]] == 0)
        {
            dist[edge[m][i]] = dist[m] + cost[m][i];
            DFS(edge[m][i]);
        }
    }

    if(dist[m] > maxi)
        maxi = dist[m];

    return;
}

int main()
{
    int t,test,n,i,j,m,fnode[SZ],u,v,w;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            edge[u].push_back(v);
            edge[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        maxi = 0;
        for(i=0;i<n;i++)
            dist[i]=0,color[i]=0;
        for(i=0;i<n;i++)
        {
            DFS(i);
            fnode[i] = maxi;
            maxi = 0;
            for(j=0;j<n;j++)
                dist[j]=0,color[j]=0;
        }
        printf("Case %d:\n",t);
        for(i=0;i<n;i++)
            printf("%d\n",fnode[i]);
        for(i=0;i<n;i++)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
