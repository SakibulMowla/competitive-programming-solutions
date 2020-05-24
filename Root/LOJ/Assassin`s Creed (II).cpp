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

#define SZ 1010

vector <int> adj[SZ];
int col[SZ], low[SZ], tim[SZ], timer, components;
int group_id[SZ];
stack <int> S;


void scc(int u){
    int i, v, tem, k;
    col[u] = 1;
    low[u] = tim[u] = timer++;
    S.push(u);
    k = sz(adj[u]);

    REP(i, k){
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tim[v]);
        else if(col[v] == 0){
            scc(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == tim[u]){
        do{
            tem = S.top();S.pop();
            group_id[tem] = components;
            col[tem] = 2;
        }while(tem != u);
        components++;
    }
}

void TarjanSCC(int n){
    int i;
    timer = components = 0;
    memset(col, 0, sizeof(int)*(n+5));
    while(!S.empty()) S.pop();
    REP1(i, 1, n) if(!col[i]) scc(i);
}

int in_deg[SZ], out_deg[SZ];

void make_DAG(int n){
    int i, j, u, v, k;

    memset(in_deg, 0, sizeof(int)*(components+5));
    memset(out_deg, 0, sizeof(int)*(components+5));

    REP1(i, 1, n){
        k = sz(adj[i]);
        REP(j, k){
            u = group_id[i];
            v = group_id[ adj[i][j] ];
            if(u != v)
                in_deg[v]++, out_deg[u]++;
        }
    }
}

int main() {
    freopen("1.txt", "r", stdin);
    int test=0, t, i, j, k, n, m, ans, in, out;

    RD(t);

    while(t--){
        RD(n, m);

        REP1(i, 1, n) clr(adj[i]);

        REP(i, m){
            RD(j, k);
            adj[j].pb(k);
        }

        TarjanSCC(n);
        make_DAG(n);

        ans = in = out = 0;

        REP(i, components){
            if(in_deg[i] == 0 && out_deg[i] == 0) ans++;
            else if(in_deg[i] == 0) in++;
            else if(out_deg[i] == 0) out++;
        }

        ans += max(in, out);

        printf("Case %d: %d\n", ++test, ans);
    }


    return 0;
}













