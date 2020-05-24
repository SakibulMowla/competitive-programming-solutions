#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
#define SZ 55
queue <int> q;
char arr[SZ][SZ];
int dist[SZ][SZ] , r , c;

int x[]={-1,1,0,0};
int y[]={0,0,-1,1};

int bfs(int s1,int s2,int t1,int t2)
{
    while( !q.empty() ) q.pop();
    memset(dist,0,sizeof(dist));
    dist[s1][s2] = 0;
    q.push(s1);
    q.push(s2);
    int i,j,u,v,a,b;

    while( !q.empty() )
    {
        u = q.front();q.pop();
        v = q.front();q.pop();
        for(i=0;i<4;i++)
        {
            a = u + x[i];
            b = v + y[i];
            if(a>=0 && b>=0 && a<r && b<c && arr[a][b]!='#' && !dist[a][b])
            {
                dist[a][b] = dist[u][v] + 1;
                q.push(a);
                q.push(b);
                if(a == t1 && b == t2)
                    return dist[a][b];
            }
        }
    }
    return dist[t1][t2];
}

struct data {int start,end,cost;};
bool comp(data u,data v)
{
    return u.cost < v.cost;
}

#define Union(a,b) par[find(a)] = find(b)
int par[110];

int find(int r)
{
    if(r == par[r])
        return r;
    return par[r] = find(par[r]);
}

void makeset(int n)
{
    int i;
    for(i=0;i<=n;i++)
        par[i] = i;
}

vector <data> vec;

int mst()
{
    sort(vec.begin(),vec.end(),comp);
    int i,j,u,v,t_dist;
    t_dist = 0;
    for(i=0;i<vec.size();i++)
    {
        u = find(vec[i].start);
        v = find(vec[i].end);
        if(u == v)
            continue;
        Union(u,v);
        t_dist += vec[i].cost;
    }
    return t_dist;
}

struct data1{int x,y;};

void take_process()
{
    data1 point[110];
    int i,j,k;
    data u;
    scanf("%d %d",&c,&r);
    for(i=0;i<r;i++)
        scanf(" %[^\n]",arr[i]);
    k = 0;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(arr[i][j] == 'A' || arr[i][j] == 'S')
            {
                point[k].x = i;
                point[k].y = j;
                k++;
            }
    vec.clear();
    makeset(k);
    for(i=0;i<k;i++)
        for(j=i+1;j<k;j++)
        {
            u.start = i;
            u.end = j;
            u.cost = bfs(point[i].x , point[i].y , point[j].x , point[j].y);
            vec.push_back(u);
        }
}

int main()
{
    int test;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        take_process();
        printf("%d\n",mst());
    }
    return 0;
}
