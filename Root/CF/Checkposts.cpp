///0 - Based Index

#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <stack>
#include <string.h>
using namespace std;

typedef long long ll;

#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR        1e-5
#define PRE        1e-8
#define SZ(s)      ((int)s.size())
#define LL           long long
#define ISS         istringstream
#define OSS        ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcount(mask)
#define lim          100010 //number of nodes
//No problem in multiple edges and self loop
//0 based
VI adj[lim];//only adj should be cleared
int col[lim], low[lim], tim[lim], timer;
int group_id[lim], n, m, components;//components=number of components group_id = which node belongs to which node
stack<int>S;

ll cost[lim], total_cost, ways;

const ll mod = 1000000007LL;

void scc(int u)
{
    int i,v,tem;
    col[u]=1;
    low[u]=tim[u]=timer++;
    S.push(u);
    fr(i,0,SZ(adj[u])-1)
    {
        v=adj[u][i];
        if(col[v]==1)
            low[u]=min(low[u],tim[v]);
        else if(col[v]==0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }

    ll minim = 1e10;
    ll cnt = 0;

    //SCC checking...
    if(low[u]==tim[u])
    {
        do
        {
            tem=S.top();S.pop();
            if(cost[tem] < minim){
                minim = cost[tem];
                cnt = 1;
            }
            else if(cost[tem] == minim){
                cnt++;
            }
            group_id[tem]=components;
            col[tem]=2; //Completed...
        }while(tem!=u);
        components++;

        total_cost += minim;
        ways = (ways * cnt) % mod;
    }
}

int TarjanSCC() //some change may be required here
{
    int i;
    timer=components=0;
    mem(col,0);
    while(!S.empty()) S.pop();
    fr(i,0,n-1) if(col[i]==0) scc(i);
    return components;
}

//VI nadj[lim];//new adjcency list after SCC(DAG)
//void MakeNewDAG_Graph()
//{
//    int i,j,u,v;
//
//    fr(i,0,components-1) nadj[i].clear();
//
//    fr(i,0,n-1)
//    {
//        fr(j,0,SZ(adj[i])-1)
//        {
//            u=group_id[i];
//            v=group_id[adj[i][j]];
//            if(u!=v)
//                nadj[u].pb(v);
//        }
//    }
//}

//void add(int ina,int inb)
//{
//    adj[ina].pb(inb);
//}


int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    int i,j,t,cas=0,u,v,ans;

    while(scanf("%d",&n)==1)
    {
        total_cost = 0LL;
        ways = 1LL;
        fr(i,0,n-1) adj[i].clear();

        for(i=0; i<n; i++) scanf("%I64d",&cost[i]);

        scanf("%d",&m);
        fr(i,1,m)
        {
            scanf("%d %d",&u,&v);
            u--, v--;
            adj[u].pb(v);
        }

        TarjanSCC();

        printf("%I64d %I64d\n",total_cost,ways);
//        printf("Total Groups: %d\n",components);
//        MakeNewDAG_Graph();
//        printf("NewGraphLinkUsingSCC: this graph is directed acyclic graph:\n");
//    //this link between groups no.....
//        fr(i,0,components-1)
//        {
//            fr(j,0,SZ(nadj[i])-1)
//            {
//                u=i;
//                v=nadj[i][j];
//                print2(u,v);
//            }
//        }
    }
    return 0;
}
/*
Input:
8 14
0 1
1 2
1 5
1 4
2 6
2 3
3 2
3 7
4 5
5 6
7 6
7 3
6 5
4 0
Output:
Total Groups: 3
NewGraphLinkUsingSCC: this graph is directed acyclic graph:
1 0
1 0
2 1
2 0
2 0


Another Input:
6 6
0 1
1 2
2 1
3 4
4 5
5 4
Total Groups: 4
NewGraphLinkUsingSCC: this graph is directed acyclic graph:
1       0
3       2

*/
