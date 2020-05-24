#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define clr(name,val) memset(name,(val),sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 10000000
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)
#define maxnode 10010

using namespace std;

vector<int> adj[maxnode];
vector<int> point;
int distime[maxnode],height[maxnode],root,col[maxnode],id;

void dfs_point(int u,int par)
{
    int v,child=0;
    distime[u]=height[u]=id++;
    for(int i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if(v==par) continue;
        if(!distime[v])
        {
            child++;
            dfs_point(v,u);
            height[u]=min(height[u],height[v]);///height update.
            if(distime[u]<=height[v]&&u!=root&&!col[u])
            {
                point.psb(u);///find point.
                col[u]=true;
            }
        }
        else if(distime[u]>distime[v]) height[u]=min(distime[v],height[u]);///back edge.
    }
    if(u==root&&child>=2&&!col[u])
    {
        col[u]=true;
        point.psb(u);///root case.
    }
    return ;
}

int main()
{
    int test,n,m,u,v,res,cas=0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n;i++) adj[i].clear();
        clr(distime,0);
        clr(height,0);
        clr(col,0);
        point.clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].psb(v);
            adj[v].psb(u);
        }
        id=1;
        for(root=1;root<=n;root++)
        {
            if(!distime[root])
            {
                dfs_point(root,root);
            }
        }
        printf("Case %d: %d\n",++cas,point.size());
    }
    return 0;
}
/*
1
8 9
1 2
1 8
8 2
2 3
3 4
2 4
3 5
5 7
5 6
*/
