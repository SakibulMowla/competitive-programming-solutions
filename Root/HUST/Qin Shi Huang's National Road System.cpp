#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

#define X first
#define Y second

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ  1010
#define SZ1 1000010
const ll inf = 1LL<<28;
const ll mod = 1LL;





struct data
{
    double x, y;
};

data point[SZ];

struct data1
{
    int x, y;
    double z;
    data1() {}
    data1(int a, int b, double c)
    {
        x = a;
        y = b;
        z = c;
    }
};

vector <data1> adj; // MST

bool comp(data1 p, data1 q)
{
    return p.z < q.z;
}

int ppl[SZ];
int par[SZ];

double dist(int a, int b)
{
    double d;
    d = sqrt( (point[a].x-point[b].x)*(point[a].x-point[b].x) + (point[a].y-point[b].y)*(point[a].y-point[b].y) );
    return d;
}

int find(int r)
{
    if(r == par[r])
        return r;
    return par[r] = find(par[r]);
}

vector <int> nadj[SZ];
vector <double> edge[SZ];

double mst()
{
    sort(adj.begin(), adj.end(), comp);

    int i, j, k, x, y;
    double cost = 0;

    k = sz(adj);

    for(i=0; i<k; i++)
    {
        x = find( adj[i].x );
        y = find( adj[i].y );

//        printf()

        if(x == y) continue;

        cost += adj[i].z;
        par[x] = y;

        nadj[ adj[i].x ].push_back( adj[i].y );
        edge[ adj[i].x ].push_back( adj[i].z );
        nadj[ adj[i].y ].push_back( adj[i].x );
        edge[ adj[i].y ].push_back( adj[i].z );
    }

    return cost;
}

bool col[SZ];
double best;
double mcost;
int strt;
int node;

void dfs(int u, double road)
{
    col[u] = 1;

    int i, j, k;

    if(u != strt)
        best = max(best, (double)(ppl[strt] + ppl[u]) / (mcost-road) );

    k = sz(nadj[u]);

    for(i=0;i<k;i++)
    {
        j = nadj[u][i];
        if(col[j] != 1)
            dfs(j, max(road, edge[u][i]));
    }
}

int main()
{
    int t, i, j, k, n, m;
    double d, cost;

    scanf("%d",&t);


    while(t--)
    {
        scanf("%d",&node);

        for(i=0; i<node; i++)
        {
            scanf("%lf %lf",&point[i].x, &point[i].y);
            scanf("%d",&ppl[i]);
        }

        adj.clear();
        for(i=0; i<=node; i++)
        {
            par[i] = i;
            nadj[i].clear();
            edge[i].clear();
        }

        for(i=0; i<node; i++)
            for(j=i+1; j<node; j++)
            {
                d = dist(i, j);
                adj.push_back( data1(i, j, d) );
            }

        cost = mst();
        best = 0;
        mcost = cost;

//        printf("mcost = %lf\n",mcost);

        for(i=0; i<node; i++)
        {
            for(j=0;j<=node;j++)
                col[j] = 0;
            strt = i;
            dfs(i, 0);
        }

        printf("%.2lf\n",best);
    }



    return 0;
}















