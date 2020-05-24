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
void RD(ll &x){scanf("%I64d",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%I64d%I64d",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%I64d\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

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

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = (1e15)+1;
const ll mod = 1LL;

#define SZ 100010

struct data{
    ll to, cost;
    data(){}
    data(int a, int b){
        to = a; cost = b;
    }
    bool operator < (const data &x) const{
        return cost > x.cost;
    }
};

struct data1{
    int a, b, c;
    data1(int q, int w, int e){
        a = q, b = w, c = e;
    }
};

vector <data1> edge;
vector <data> adj[SZ];
ll dist[SZ];
priority_queue <data> pq;
int par[SZ];

void dijkstra(int strt, int n){
    int i, j, k, u, v, x, y;
    data p;

    while(!pq.empty()) pq.pop();
    REP1(i, 1, n) dist[i] = inf;
    dist[strt] = 0;
    pq.push(data(strt, 0));
    par[strt] = -1;

    while(!pq.empty()){
        p = pq.top(); pq.pop();
        u = p.to;
        v = p.cost;

        k = sz(adj[u]);

        REP(i, k){
            x = adj[u][i].to;
            y = adj[u][i].cost;
            if(dist[x] > v + y){
                dist[x] = v + y;
                pq.push(data(x, dist[x]));
                par[x] = u;
            }
        }
    }

    return ;
}

map <pii , int> mp;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m, s, i, j, u, v, k, ans, x, y;
    ll need1, need2, l;

    while(scanf("%d",&n) == 1){
        RD(m, s);
        clr(edge);
        REP1(i, 1, n) clr(adj[i]);
        REP(i, m){
            RD(u, v);
            RD(k);
            adj[u].pb(data(v, k));
            adj[v].pb(data(u, k));
            edge.pb(data1(u, v, k));
        }
        RD(l);

        dijkstra(s, n);

        clr(mp);
        ans = 0;

        REP1(i, 1, n) if(dist[i] == l) ans++;

        REP(i, m){
            int a, b, c;
            a = edge[i].a;
            b = edge[i].b;
            c = edge[i].c;
            if(l-dist[a]>0 && l-dist[a]<c && c-(l-dist[a]) > l-dist[b]) ans++;
            if(l-dist[b]>0 && l-dist[b]<c && c-(l-dist[b]) >= l-dist[a]) ans++;
        }

        PR(ans);
    }



    return 0;
}















