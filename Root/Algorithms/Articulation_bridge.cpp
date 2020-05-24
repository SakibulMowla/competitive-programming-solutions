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
#define maxnode 10005

using namespace std;

vector<int> adj[maxnode];
vector<pair<int,int> > bridge;
int distime[maxnode],height[maxnode],root,id;

void dfs_bridge(int u,int par)
{
    int v,p,q;
    distime[u]=height[u]=id++;
    for(int i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(v==par) continue;
        if(!distime[v])
        {
            dfs_bridge(v,u);
            height[u]=min(height[u],height[v]);///height update.
            if(distime[u]<height[v])
            {
                p=u,q=v;
                if(p>q) swap(p,q);
                bridge.psb(mp(p,q));///find bridge.
            }
        }
        else if(distime[u]>distime[v]) height[u]=min(distime[v],height[u]);
    }
    return ;
}

bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.fs==b.fs) return a.sc<b.sc;
    return a.fs<b.fs;
}

int main()
{
    int n,m,test,cas=0,u,v;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        bridge.clear();
        clr(distime,0);
        clr(height,0);
        for(int i=0; i<=n; i++) adj[i].clear();
        id=1;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].psb(v);
            adj[v].psb(u);
        }
        for(int i=0; i<n; i++)
        {
            if(!distime[i])
            {
                root=i;
                dfs_bridge(i,-1);
            }
        }
        cout<<bridge.size()<<endl;
        sort(bridge.begin(),bridge.end(),comp);
        for(int i=0;i<bridge.size();i++)
        {
            cout<<bridge[i].fs<<" "<<bridge[i].sc<<endl;
        }
    }
    return 0;
}
/*
5
8 7
0 1
5 0
1 2
2 3
3 4
6 7
1 3
*/
