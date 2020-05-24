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

typedef long long ll;
typedef pair<ll,ll> pii;

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

#define SZ  17000
#define SZ1 20010
const ll inf = 1LL<<28;
const ll mod = 1LL;

struct data
{
    int x, y;
};

data val[SZ];

vector <int> adj[SZ];
int col[SZ], low[SZ], tim[SZ], timer;
int group_id[SZ], compo;
bool logic[SZ];
stack <int> S;


void scc(int u)
{
    int i, v, tem, k;

    col[u] = 1;
    low[u] = tim[u] = timer++;
    S.push(u);

    k = sz(adj[u]);

    for(i=0;i<k;i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tim[v]);
        else if(col[v] == 0)
        {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == tim[u])
    {
        do
        {
            tem = S.top();
            S.pop();
            group_id[tem] = compo;
            col[tem]= 2;
        }
        while(tem != u);
        compo++;
    }
}




void tarjan(int m)
{
    int i;

    for(i=0;i<=2*m+2;i++)
        col[i] = 0;

    timer = compo = 0;
    while(!S.empty()) S.pop();

    for(i=2;i<=2*m+1;i++)
        if(col[i] == 0)
            scc(i);
}


void implication_graph(int n)
{
    int i, j, k, a, b, acomp, bcomp;

    for(i=0;i<n;i++)
    {
        j = val[i].x;
        k = val[i].y;
        if(j > 0)
        {
            a = 2 * j;
            acomp = 2 * j + 1;
        }
        else
        {
            a = 2 * (-j) + 1;
            acomp = 2 * (-j);
        }

        if(k > 0)
        {
            b = 2 * k;
            bcomp = 2 * k + 1;
        }
        else
        {
            b = 2 * (-k) + 1;
            bcomp = 2 *(-k);
        }
        adj[acomp].push_back(b);
        adj[bcomp].push_back(a);
    }
}


bool two_sat(int m)
{
    int i;

    for(i=2;i<=2*m;i+=2)
    {
        if(group_id[i] == group_id[i+1])
            return false;
        else if(group_id[i] > group_id[i+1])
            logic[i/2] = false;
        else
            logic[i/2] = true;
    }

    return true;
}




//%I64d
int main()
{
    int test = 0, t, n, m, i, j, k, p, q;

    vector <int> v;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(i=0;i<=2*m+2;i++)
            adj[i].clear();

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&val[i].x,&val[i].y);
        }

        implication_graph(n);

        tarjan(m);

        printf("Case %d: ",++test);

        if(two_sat(m))
        {
            printf("Yes\n");
            v.clear();

            for(i=1;i<=m;i++)
                if(logic[i])
                    v.push_back(i);

            k = sz(v);

            printf("%d",k);

            for(i=0;i<k;i++)
                printf(" %d",v[i]);

            printf("\n");
        }
        else
            printf("No\n");
    }



    return 0;
}





















