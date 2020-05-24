#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;
typedef long long ll;

/*ll bigmod(ll a,ll b,ll m)
{
    if(b == 0) return 1%m;
    ll x = bigmod(a,b/2,m);
    x = (x * x) % m;
    if(b % 2 == 1) x = (x * a) % m;
    return x;
}*/

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

/*template <class T> T GCD(T a,T b)
{
    if(b == 0) return a;
    return GCD(b,a%b);
}

template <class T> T LCM(T a,T b)
{
    return (a*b) / GCD(a,b);
}*/

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
const double eps = 1e-6;
#define MP(a,b) make_pair(a,b)
#define EPS 1E-7
#define SZ 110

struct data
{
    double x, y;
};
data arr[SZ];
ll n,m;
double s,v;
vector <int> adj[SZ];
bool col[SZ];
ll par[SZ];

double dist(double a,double b,double c,double d)
{
    return sqrt( (a-c) * (a-c) + (b-d) * (b-d) );
}

bool dfs(ll u)
{
    ll i,j;
    for(i=0; i<adj[u].size(); i++)
    {
        j = adj[u][i];
        if(col[j] == 0)
        {
            col[j] = 1;
            if(par[j] == -1 || dfs(par[j]))
            {
                par[j] = u;
                return true;
            }
        }
    }
    return false;
}

ll BPM()
{
    ll i,ret=0;
    for(i=0; i<m; i++)
    {
        memset(col,0,sizeof(col));
        if(dfs(i))
            ret++;
    }
    return ret;
}

//%I64d
int main()
{
    ll i,j,k;
    double a,b;
    while(cin >> n >> m >> s >> v)
    {
        s = s * v;
        for(i=0; i<n; i++)
            cin >> arr[i].x >> arr[i].y ;

        for(i=0;i<m;i++)
        {
            adj[i].clear();
        }
        memset(par,-1,sizeof(par));
        for(i=0; i<m; i++)
        {
            cin >> a >> b;
            for(j = 0; j<n; j++)
            {
                if(dist(arr[j].x,arr[j].y,a,b) < s || fabs(dist(arr[j].x,arr[j].y,a,b) - s) < eps)
                    adj[i].push_back(j);
            }
        }
        k = BPM();
        printf("%lld\n",n-k);
    }

    return 0;
}
