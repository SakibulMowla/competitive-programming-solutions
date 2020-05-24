#include "stdio.h"
#include "string.h"
#include "vector"
#include "queue"
#include "iostream"

using namespace std;

#define SZ 2010

const int inf = 1<<28;

vector <int> edge[SZ];
bool airport[SZ];
int dist[SZ];
queue <int> Q;

void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        edge[i].clear();
        airport[i] = false;
    }
}

int BFS(int n,int start,int target)
{
    if(start == target) return 0;
    int i,j,u,d;
    for(i=0;i<=n;i++) dist[i] = inf;
    while( !Q.empty() ) Q.pop();
    dist[start] = airport[start] ? 0 : 1;
    Q.push(start);

    while( !Q.empty() )
    {
        u = Q.front() ; Q.pop();
        for(i=0;i<edge[u].size();i++)
        {
            j = edge[u][i];
            d = airport[j] ? dist[u] : dist[u] + 1;
            if(d < dist[j])
            {
                dist[j] = d;
                Q.push(j);
            }
        }
    }
    if(dist[target] == inf) return -1;
    return dist[target];
}

int main()
{
//    freopen("1.txt","r",stdin);
    int t=0,test,n,m,k,i,j,u,v;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&n,&m,&k);
        init(n);
        for(i=0;i<k;i++)
        {
            scanf("%d",&j);
            airport[j] = true;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        printf("Case %d:\n",++t);
        scanf("%d",&i);
        while(i--)
        {
            scanf("%d %d",&u,&v);
            printf("%d\n",BFS(n,u,v));
        }
        printf("\n");
    }

    return 0;
}
