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

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

int par[SZ];
bool col[SZ];
vector <int> adj[SZ];
map <int, int> M;

bool dfs(int u)
{
    if(col[u]) return false;

    int i, k, v;
    k = sz(adj[u]);

    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(col[v] == 0)
        {
            col[v] = 1;
            if(par[v] == -1 || dfs(par[v]))
            {
                par[v] = u;
                M[u] = v - 501;
                return true;
            }
        }
    }

    return false;
}

int bpm(int n)
{
    int i, j, ret = 0;

    for(i=0; i<=n+505; i++) par[i] = -1;

    for(i=0; i<n; i++)
    {
        for(j=0; j<=n+505; j++) col[j]  = 0;
        if(dfs(i)) ret++;
    }

//    printf("ret = %d\n",ret);

    return ret;
}


//%I64d
int main()
{
    int a, b, i, j, k, n, m, l1, l2;
    vector <int> v1, v2;

    while(scanf("%d %d",&a,&b) == 2)
    {

        scanf("%d",&n);

        v1.clear();
        v2.clear();
        M.clear();

        for(i=0; i<=n; i++)
            adj[i].clear();

        for(i=0; i<n; i++)
        {
            scanf("%d %d",&j,&k);
            if(!k) v1.push_back(j);
            else v2.push_back(j);
        }

        l1 = sz(v1);
        l2 = sz(v2);

        for(i=0; i<l1; i++)
            for(j=0; j<l2; j++)
            {
                if(v2[j] > v1[i] && ( (v2[j]-v1[i]) >= a || (v2[j]-v1[i]) <= b ) )
                    adj[i].push_back(j+501);
            }

        if(bpm(n/2) == n/2)
        {
            printf("No reason\n");
            for(i=0;i<n/2;i++)
                printf("%d %d\n",v1[i], v2[ M[i] ]);
        }
        else printf("Liar\n");
    }



    return 0;
}





/*

6 3
8
1 0
2 0
3 0
4 0
4 1
4 1
4 1
4 1

ans = true

*/







