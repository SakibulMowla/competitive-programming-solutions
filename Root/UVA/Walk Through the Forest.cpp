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
const int inf = (1e9)+5;
const ll mod = 1LL;

#define SZ  1010

struct data{
    int to, cost;
    data(){}
    data(int a, int b){
        to = a, cost = b;
    }
    bool operator < (const data &x) const{
        cost > x.cost;
    }
};

vector <data> adj[SZ];
int dist[SZ], dp[SZ];
priority_queue <data> pq;

void dijkstra(int n){
    while(!pq.empty()) pq.pop();

    int i, k, u, v, j;
    for(i=2; i<=n; i++)
        dist[i] = inf;
    dist[1] = 0;
    pq.push(data(1, 0));

    while(!pq.empty()){
        u = pq.top().to;
        v = pq.top().cost;
        pq.pop();
        k = sz(adj[u]);
        for(i=0; i<k; i++){
            j = adj[u][i].to;
            if(adj[u][i].cost + dist[u] < dist[j]){
                dist[j] = adj[u][i].cost + dist[u];
                pq.push(data(j, dist[j]));
            }
        }
    }
}

int solve(int n){
//    printf("n = %d\n",n);
    if(n == 2) return 1;

    int &ret = dp[n];
    if(~ret) return ret;

    int i, j, k, l;

    ret = 0;
    k = sz(adj[n]);

    for(i=0; i<k; i++){
        j = adj[n][i].to;
        l = adj[n][i].cost;
        if(dist[n]+l == dist[j])
            ret += solve(j);
    }

    return ret;
}

map <pii, int> mp;
map <pii, int> ::iterator it;

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m, i, j, k;

    while(scanf("%d",&n) == 1 && n){
        for(i=1;i <=n; i++){
            clr(adj[i]);
        }
        clr(mp);
        scanf("%d",&m);
        while(m--){
            scanf("%d %d %d",&i,&j,&k);
            if(i > j) swap(i, j);
            if(mp.find(MP(i, j)) == mp.end())
                mp[MP(i, j)] = k;
            else
                mp[MP(i, j)] = min(mp[MP(i, j)], k);
        }

        for(it=mp.begin(); it!=mp.end(); it++){
            adj[it->X.X].pb(data(it->X.Y, it->Y));
            adj[it->X.Y].pb(data(it->X.X, it->Y));
        }

        dijkstra(n);
//        for(i=1; i<=n; i++)
//            printf("i = %d dist = %d\n",i,dist[i]);
        mem(dp, -1);
        printf("%d\n",solve(1));
    }

    return 0;
}













