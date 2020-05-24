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


using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

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
const ll inf = 1e18;
const ll mod = 1LL;

#define SZ  110

/// For DP
int cur;
int col[SZ][SZ];
int col2[SZ][SZ][SZ];
ll dp[SZ][SZ];
ll dp2[SZ][SZ][SZ];


ll val[SZ];
int sub_size[SZ];

/// For new adjacency list
vector <int> tmp_adj[SZ], adj[SZ];
bool vis[SZ];

ll gen(int, int, int);
ll solve(int, int);

ll gen(int node, int child, int left)
{
//    printf("Node Child Left %d %d %d\n", node, child, left);
    ll &ret = dp2[node][child][left];
    if(col2[node][child][left] == cur) return ret;
    col2[node][child][left] = cur;

    if(child == 0)
    {
        return ret = solve(adj[node][child], left);
    }
    ll ans = 0LL;
    for(int i = 0; i <= left; i++)
    {
        ans = max(ans, solve(adj[node][child], i) + gen(node, child-1, left-i));
    }
    return ret = ans;
}

ll solve(int n, int k)
{
    ll &ret = dp[n][k];
    if(col[n][k] == cur) return ret;
    col[n][k] = cur;
    if(k == 0) ret = 0LL;
    else if(k == 1) ret = val[n];
    else if(k > sub_size[n]) ret = -inf;
    else ret = val[n] + gen(n, sz(adj[n])-1, k-1);
//    printf("N adj sub K Ret = %d %d %d %d %lld\n", n, sz(adj[n]), sub_size[n], k, ret);
    return ret;
}

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < sz(tmp_adj[u]); i++)
    {
        int v = tmp_adj[u][i];
        if(vis[v]) continue;
        adj[u].pb(v);
        dfs(v);
        sub_size[u] += sub_size[v];
    }
    sub_size[u]++;
//    printf("u = %d sub = %d\n", u, sub_size[u]);
    return;
}

int main()
{
#if defined JESI
//    freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    int n, k;
    while(scanf("%d %d", &n, &k) == 2)
    {
        for(int i = 0; i < n; i++)
        {
            clr(adj[i]);
            clr(tmp_adj[i]);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &val[i]);
            sub_size[i] = 0;
        }
        for(int i = 0; i < n - 1; i++)
        {
            int j, k;
            scanf("%d %d", &j, &k);
            tmp_adj[j].pb(k);
            tmp_adj[k].pb(j);
        }

        /// preparing new adjacency list
        mem(vis, 0);
        dfs(0);

        ++cur;
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, solve(i, k));
        }

        printf("%lld\n", ans);
    }

    return 0;
}













