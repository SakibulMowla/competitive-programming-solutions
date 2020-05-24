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
#include <deque>
#include <assert.h>
#include <bitset>


using namespace  std;

typedef long long ll;


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ 50000+10

vector <int> adj[SZ];
int col[SZ], low[SZ], tym[SZ], timer;
int group_id[SZ], compo;
stack <int> S;

int val[SZ];
int chunk[SZ];

void SCC(int u)
{
    col[u] = 1;
    low[u] = tym[u] = timer++;
    S.push(u);

    for(int i = 0; i < sz(adj[u]); i++)
    {
        int v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tym[v]);
        else if(col[v] == 0)
        {
            SCC(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == tym[u])
    {
        int sum = 0, tem;
        do
        {
            tem = S.top(); S.pop();
            group_id[tem] = compo;
            col[tem] = 2;
            sum += val[tem];
        } while(tem != u);
        chunk[compo] = sum;
        compo++;
    }
}

int TarjanSCC(int n)
{
    timer = compo = 0;
    mem(col, 0);
    while(!S.empty()) S.pop();
    for(int i = 0; i < n; i++)
        if(col[i] == 0)
            SCC(i);
    return compo;
}

vector <int> nadj[SZ];

void Make_DAG(int n)
{
    for(int i = 0; i < compo; i++)
        nadj[i].clear();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < sz(adj[i]); j++)
        {
            int u = group_id[i];
            int v = group_id[ adj[i][j] ];
            if(u != v)
            {
                nadj[u].pb(v);
            }
        }
    return;
}

int dp[SZ];

int dfs(int u)
{
    int &ret = dp[u];

    if(col[u] == 1) return ret;
    col[u] = 1;
    ret = 0;

    for(int i = 0; i < sz(nadj[u]); i++)
    {
        int v = nadj[u][i];
        ret = max(ret, dfs(v));
    }

    ret += chunk[u];

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test = 0, t;

    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            adj[i].clear();

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &val[i]);
            int k;
            scanf("%d", &k);
            while(k--)
            {
                int j;
                scanf("%d", &j);
                adj[i].pb(j);
            }
        }

        TarjanSCC(n);
        Make_DAG(n);

        mem(col, 0);

        int ans = 0;
        for(int i = 0; i < compo; i++)
            ans = max(ans, dfs(i));

        printf("Case %d: %d\n", ++test, ans);
    }

    return 0;
}








