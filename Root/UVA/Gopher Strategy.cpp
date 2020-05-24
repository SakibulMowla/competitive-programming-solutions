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

#define SZ  110
#define eps 1e-6

struct data{
    double x, y;
};

data gropher[SZ], hole[SZ];

int par[SZ];
bool col[SZ];
vector <int> adj[SZ];

bool dfs(int u){
    if(col[u]) return false;

    int i, k, v;
    k = sz(adj[u]);

    REP(i, k){
        v = adj[u][i];
//        printf("uv %d %d\n",u,v);
        if(col[v] == 0){
            col[v] = 1;
            if(par[v] == -1 || dfs(par[v])){
//                    printf("DFS\n");
                par[v] = u;
                return true;
            }
        }
    }

    return false;
}

int bpm(int n, int m){
    int i, j, ret = 0;

    REP1(i, 1, 100) par[i] = -1;
    REP1(i, 1, m){
        REP1(j, 1, 100) col[j] = 0;
        if(dfs(i)) ret++;
    }

    return ret;
}

void build_graph(int n, int m, double mid){
    int i, j;
    double d;

    REP1(i, 1, m) clr(adj[i]);

    REP1(i, 1, m)
        REP1(j, 1, n) {
            d = sqrt( (gropher[i].x - hole[j].x)*(gropher[i].x - hole[j].x) + (gropher[i].y - hole[j].y) * (gropher[i].y - hole[j].y) );
            if(d <= mid)
//            if(fabs(d-mid) <= eps)
                adj[i].pb(j+50)/*, printf("yes %d %d %lf\n",i,j,d)*/;
        }
}

bool f(int n, int m, int k, double mid){
    build_graph(n, m, mid);

    int res = bpm(n, m);
//    printf("res = %d\n",res);

    return res >= (m-k);
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test=0, t, i, j, k, n, m;
    double lo, hi, mid, ans;

    RD(t);

    while(t--){
        RD(m, n);
        RD(k);

        REP1(i, 1, m) RD(gropher[i].x, gropher[i].y);
        REP1(i, 1, n) RD(hole[i].x, hole[i].y);

        lo = 0;
        hi = 4e9;
        ans = -1;

        REP(i, 70){
            mid = (lo + hi) / 2;
            if(f(n, m, k, mid))
                ans = mid, hi = mid;
            else
                lo = mid;
//            printf("mid = %lf\n",mid);
        }

//        if(f(n, m, k, 1.5))
//            ans = 1.5;
//        else
//            ans = -1;

        printf("Case #%d:\n",++test);
        ans == -1 ? printf("Too bad.\n") : printf("%.3lf\n",ans);
        puts("");
    }


    return 0;
}













