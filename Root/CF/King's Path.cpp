#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define SZ 1000000000
#define X first
#define Y second
#define clear(a) a.clear;

typedef pair<int , int> pii;

map <pii , bool> color,grid;
map <pii , int> dist;

bool valid(int u,int v)
{
    if( u>=0 && u<=SZ && v>=0 && v<=SZ && grid[make_pair(u,v)] && !color[make_pair(u,v)] )
        return true;
    return false;
}

int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};

int bfs(int s1,int t1,int s2,int t2)
{
    dist[make_pair(s1,t1)] = 0;
    color[make_pair(s1,t1)] = true;

    queue <pii> q;
    q.push(make_pair(s1,t1));

    while( !q.empty() )
    {
        int a = q.front().X ,  b = q.front().Y;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int u = a + x[i]  ,  v = b + y[i];
            if(valid(u,v))
            {
                dist[make_pair(u,v)] = dist[make_pair(a,b)] + 1;
                color[make_pair(u,v)] = true;
                q.push(make_pair(u,v));
                if(u==s2 && v==t2)
                    return dist[make_pair(u,v)];
            }
        }
    }
    return -1;
}

int main()
{
    int i,j,n,r,a,b,s1,t1,s2,t2;
    scanf("%d %d %d %d",&s1,&t1,&s2,&t2);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&r,&a,&b);
        for(j=a;j<=b;j++)
        {
            grid[make_pair(r,j)] = true;
        }
    }
    printf("%d\n",bfs(s1,t1,s2,t2));

    return 0;
}
