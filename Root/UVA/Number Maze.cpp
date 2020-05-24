#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

#define for(a,b) for(a=0;a<b;a++)

using namespace std;

vector <int> vc[1000];
int r,c;
const int inf = 1000000000;
int dist[1000][1000];

struct data
{
    int row,col,dist;
//    bool operator < (const data& p) const {
//        return dist > p.dist;
//    }
};

int x[]={-1,1,0,0};
int y[]={0,0,-1,1};

priority_queue <data> q;

int dijkstra()
{
    int i,j;
    for(i,r)for(j,c)dist[i][j] = inf;

    while( !q.empty() )
        q.pop();
    data u,v;
    u.row=0;
    u.col=0;
    u.dist=vc[u.row][u.col];
    q.push(u);
    dist[0][0] = vc[0][0];

    while( !q.empty() )
    {
        u = q.top();
        q.pop();
        int ucost = u.dist;
        for(i,4)
        {
            v.row = u.row + x[i];
            v.col = u.col + y[i];
            if(v.row>=0 && v.col>=0 && v.row<r && v.col<c)
            {
                v.dist = vc[v.row][v.col] + ucost;
                if(dist[v.row][v.col] > v.dist)
                {
                    dist[v.row][v.col] =  v.dist;
                    q.push(v);
                }
            }
        }
    }

    return dist[r-1][c-1];
}

int main()
{
    int test,i,j,ans,num;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&r,&c);
        for(i,r)for(j,c){scanf("%d",&num);vc[i].push_back(num);}

        ans = dijkstra();
        printf("%d\n",ans);

        for(i,r)vc[i].clear();
    }

    return  0;
}
