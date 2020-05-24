#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define SZ 1010

vector <int> v[SZ];
bool color[SZ];
int reachable[SZ];

int n,m,k;

void DFS(int node)
{
    reachable[node]++;
    color[node] = 1;
    int i,j,k;
    for(i=0;i<v[node].size();i++)
    {
        if(color[v[node][i]] == 0)
            DFS(v[node][i]);
    }
    return;
}

int main()
{
    int city[110],t,test,i,node1,node2,count;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        memset(reachable , 0 ,sizeof(reachable));
        scanf("%d %d %d",&k,&n,&m);
        for(i=1;i<=k;i++)
            scanf("%d",&city[i]);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&node1,&node2);
            v[node1].push_back(node2);
        }
        for(i=1;i<=k;i++)
        {
            memset(color , 0 ,sizeof(color));
            DFS(city[i]);
        }
        count = 0;
//        printf("k=%d reachable[5]=%d\n",k,reachable[5]);
        for(i=1;i<=n;i++)
            if(reachable[i] == k)
                count++;
        printf("Case %d: %d\n",t,count);
        for(i=0;i<=n;i++)
            v[i].clear();
    }

    return 0;
}
