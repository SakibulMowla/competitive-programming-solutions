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

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%lld",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%lld\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


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
const int inf = 1;
const ll mod = 1LL;

#define SZ  40000+10

vector <pii> adj[SZ];

int par[SZ][22], cost[SZ][22], level[SZ];
bool vis[SZ];

void dfs(int u)
{
//    printf("u = %d\n",u);
    vis[u] = 1;

    int i, j, k=sz(adj[u]);

    for(i=0; i<k; i++)
    {
        j = adj[u][i].X;
        if(vis[j] == 1) continue;
        par[j][0] = u;
        cost[j][0] = adj[u][i].Y;
        level[j] = level[u] + 1;
        dfs(j);
    }

    return;
}

void process_lca(int n)
{
    int i, j, h, lev;

    for(h=1; (1<<h)<=n; h++);
    --h;

    for(i=0; i<=n; i++)
        for(j=0; j<=h; j++)
            par[i][j] = -1, cost[i][j] = 0;

    level[1] = 0;
    dfs(1);

    for(lev=1; lev<=h; lev++)
        for(i=1; i<=n; i++)
            if(par[i][lev-1] != -1)
                cost[i][lev] = cost[i][lev-1] + cost[ par[i][lev-1] ][lev-1],
                par[i][lev] = par[ par[i][lev-1] ][lev-1];
    return;
}

int query(int p, int q)
{
    if(level[p] < level[q])
        swap(p, q);

    int i, h, ans=0;

    for(h=1; (1<<h)<=level[p]; h++);
    --h;

    for(i=h; i>=0; i--)
    {
        if(level[p] - (1<<i) >= level[q])
        {
            ans += cost[p][i];
            p = par[p][i];
        }
    }

    if(p == q) return ans;

    for(i=h; i>=0; i--)
        if(par[p][i] != -1 && par[q][i] != -1 && par[p][i] != par[q][i])
        {
            ans += cost[p][i] + cost[q][i];
            p = par[p][i];
            q = par[q][i];
        }

    ans += cost[p][0] + cost[q][0];

    return ans;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    int t, n, m, i, j, k, u, v, w;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }

        for(i=0; i<n-1; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(MP(v, w));
            adj[v].pb(MP(u, w));
        }

//        printf("yes\n");

        process_lca(n);

//        printf("complete\n");

        while(m--)
        {
            scanf("%d %d",&i,&j);
//            printf("i = %d j = %d\n",i,j);
            printf("%d\n",query(i, j));
        }

        printf("\n");
    }


    return 0;
}











