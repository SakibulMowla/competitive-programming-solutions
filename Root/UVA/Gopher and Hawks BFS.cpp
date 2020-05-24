#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct data
{
    double x,y;
};

vector <int> adj[1010];
data point[1010];
int nodes, v , m , h_dist[1010];
bool color[1010];
queue <int> Q;

int bfs(int s1,int s2,int t1,int t2)
{
    if(s1 == t1 && s2 == t2) return 0;
    h_dist[0] = 0;
    color[0] = 1;
    while( !Q.empty() ) Q.pop();
    int i,j,k,u,v;

    Q.push(0);
    while( !Q.empty() )
    {
//        printf("yesy\n");
        u  = Q.front();
        Q.pop();
//        printf("size = %d\n",adj[u].size());
        for(i=0; i<adj[u].size(); i++)
        {
//            printf("n=%d c=%d\n",adj[u][i],color[adj[u][i]]);
            if(!color[adj[u][i]])
            {
//                printf("yesy\n");
                color[adj[u][i]] = 1;
                h_dist[adj[u][i]] = h_dist[u] + 1;
                Q.push(adj[u][i]);

                if(point[adj[u][i]].x == t1 && point[adj[u][i]].y == t2)
                {
//                    printf("adj[u][i] =  %d    dist = %d\n",adj[u][i],h_dist[adj[u][i]]);
//                    int a= h_dist[adj[u][i]];
//                    printf("a== %d\n",a);
                    return h_dist[u];
                }
            }
        }
    }

    return -1;
}

void take_input()
{
    getchar();
    int i,j,len;
    double s,t,dist,time;
    char arr[100];
    nodes = 2;
    while(gets(arr))
    {
//        if(strcmp(arr,"\0") == 0) break;
        len = sscanf(arr,"%lf %lf",&s,&t);
        if(len != 2) break;
        point[nodes].x = s;
        point[nodes].y = t;
        nodes++;
    }
    for(i=0; i<nodes; i++)
        adj[i].clear() , color[i] = 0;
    for(i=0; i<nodes; i++)
    {
        for(j=i+1; j<nodes; j++)
        {
            dist = sqrt( pow(point[i].x-point[j].x , 2) + pow(point[i].y-point[j].y , 2) ) ;
            time = dist / ( v * 60) ;
//            printf("time = %lf\n",time);
            if(time <= m)
                /*printf("i , j = %d %d \n",i,j),*/adj[i].push_back(j) , adj[j].push_back(i);
        }
    }
}

int main()
{
    double s1,s2,t1,t2;
    int ans;
    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&v,&m) == 2)
    {
        if(v+m == 0) break;
        scanf("%lf %lf %lf %lf",&s1,&s2,&t1,&t2);
        point[0].x = s1 , point[0].y = s2;
        point[1].x = t1 , point[1].y = t2;
        take_input();
        ans = bfs(s1,s2,t1,t2);
        if(ans == -1)
            printf("No.\n");
        else
            printf("Yes, visiting %d other holes.\n",ans);
    }

    return 0;
}
