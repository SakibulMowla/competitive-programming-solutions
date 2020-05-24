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
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 30000+10
#define SZ1 4*SZ

int gne[SZ];
vector <int> adj[SZ];

int chain_no, chain_head[SZ], chain_idx[SZ], sub[SZ]; /// HLD
int N, ptr, pos_base[SZ], base_arr[SZ], tree[SZ1]; /// Seg-Tree
int level[SZ], p[SZ][20]; /// LCA

void init(int n){
    int i, j;
    chain_no = 0;
    ptr = 0;
    for(i=0; i<=n; i++){
        clr(adj[i]);
        chain_head[i] = -1;
    }
    for(i=0; i<=n; i++)
        for(j=0; j<20; j++)
            p[i][j] = -1;
    return;
}

void dfs(int u, int par, int lvl){
    int i, j, k;

    sub[u] = 1;
    level[u] =  lvl;
    p[u][0] = par;
    k = sz(adj[u]);

    for(i=0; i<k; i++){
        j = adj[u][i];
        if(j == par) continue;
        dfs(j, u, lvl+1);
        sub[u] += sub[j];
    }

    return;
}

///chain_no chains from 0 to (chain_no-1)

void HLD(int cur, int par){
    if(chain_head[chain_no] == -1) chain_head[chain_no] = cur;
    chain_idx[cur] = chain_no;
    base_arr[++ptr] = gne[cur];
    pos_base[cur] = ptr;

    int i, j, k, indx=-1, best=-1;

    k = sz(adj[cur]);

    for(i=0; i<k; i++){
        j = adj[cur][i];
        if(j == par) continue;
        if(sub[j] > best){
            best = sub[j];
            indx = i;
        }
    }

    if(indx != -1) HLD(adj[cur][indx], cur);

    for(i=0; i<k; i++){
        j = adj[cur][i];
        if(j == par || i == indx) continue;
        chain_no++;
        HLD(j, cur);
    }

    return;
}

void make_lca(int n){
    int i, j;
    for(j=1; j<20; j++)
        for(i=1; i<=n; i++)
            if(p[i][j-1] != -1)
                p[i][j] = p[p[i][j-1]][j-1];
    return;
}

void build(int node, int b, int e){
    if(b == e){
        tree[node] = base_arr[b];
        return;
    }

    int mid = (b+e) >> 1, l = node*2, r = l+1;

    build(l, b, mid);
    build(r, mid+1, e);

    tree[node] = tree[l] + tree[r];
    return;
}

void update(int node, int b, int e, int indx, int val){
    if(b == e){
//    printf("prev = %d\n",tree[node]);
        tree[node] = val;
        return;
    }

    int mid = (b+e) >> 1, l = node*2, r = l+1;

    if(indx <= mid) update(l, b, mid, indx, val);
    else update(r, mid+1, e, indx, val);

    tree[node] = tree[l] + tree[r];
    return;
}

int query(int node, int b, int e, int f, int t){
    if(b>=f && e<=t) return tree[node];

    int mid = (b+e) >> 1, l=2*node, r = l+1, ans;

    if(f <= mid) ans = query(l, b, mid, f, t);
    if(t > mid) ans += query(r, mid+1, e, f, t);

    return ans;
}

int lca(int u, int v){
    if(level[u] < level[v]) swap(u, v);

    int i, log;
    for(log=1; (1<<log) <= level[u]; log++);
    log--;

    for(i=log; i>=0 ;i--)
        if(level[u]-(1<<i) >= level[v])
            u = p[u][i];

    if(u == v) return u;

    for(i=log; i>=0; i--){
        if(p[u][i] != -1 && p[v][i] != -1 && p[u][i] != p[v][i])
            u = p[u][i], v = p[v][i];
    }

    return p[u][0];
}

int query_up(int u, int v){
    if(u == v) return gne[u];
    int uchain, vchain = chain_idx[v], ans=0;

    while(1){
        uchain = chain_idx[u];
        if(uchain == vchain){
            ans += query(1, 1, N, pos_base[v], pos_base[u]);
            break;
        }
        ans += query(1, 1, N, pos_base[ chain_head[uchain] ], pos_base[u]);
        u = chain_head[uchain];
        u = p[u][0];
    }

    return ans;
}

int query_hld(int u, int v){
    int ancs = lca(u, v);
    return query_up(u, ancs) + query_up(v, ancs) - gne[ancs];
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    int test=0, t, n, i, j, k, q;

    RD(t);

    while(t--){
        RD(n);
        init(n);

        REP1(i, 1, n)
            RD(gne[i]);

        for(i=0; i<n-1; i++){
            RD(j, k);
            j++, k++;
            adj[j].pb(k);
            adj[k].pb(j);
        }

        dfs(1, 1, 0);
        HLD(1, 1);
        make_lca(n);
        build(1, 1, n);
        N = n;

        RD(q);
        printf("Case %d:\n",++test);

        while(q--){
            RD(k);
            RD(i, j);
            if(!k){
                printf("%d\n",query_hld(i+1, j+1));
            }
            else{
                gne[i+1] = j;
                update(1, 1, n, pos_base[i+1], j);
            }
        }
    }

    return 0;
}













