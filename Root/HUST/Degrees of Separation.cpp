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
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ  55

bool col[SZ];
int dep[SZ];
int adj[SZ][SZ];
map <string , int> mp;
int cnt, N;

void dfs(int u){
    col[u] = 1;
    cnt++;
    int i;
    for(i=1;i<=N;i++)
        if(adj[u][i] == 1 && col[i] == 0)
            dfs(i);
    return;
}

queue <int> Q;

int bfs(int u){
    while(!Q.empty()) Q.pop();
    int i, v, k;
    REP1(i, 1, N) col[i] = 0, dep[i] = 0;
    Q.push(u);
    col[u] = 1;

    while(!Q.empty()){
        v = Q.front(), Q.pop();
        for(i=1;i<=N;i++){
            if(adj[v][i] == 1 && col[i] == 0){
                col[i] = 1;
                Q.push(i);
                dep[i] = dep[v] + 1;
                k = dep[i];
            }
        }
    }

    return k;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m, i, j, k, test=0;
    string s1, s2;

    while(scanf("%d %d",&n,&m) == 2){
        if(n==0 && m==0) break;
        N = n;
        clr(mp);
        mem(adj, 0);
        k = 0;
        REP(i, m){
            cin >> s1 >> s2;
            if(mp.find(s1) == mp.end()) mp[s1] = ++k;
            if(mp.find(s2) == mp.end()) mp[s2] = ++k;
            adj[ mp[s1] ][ mp[s2] ] = 1;
            adj[ mp[s2] ][ mp[s1] ] = 1;
        }
        mem(col, 0);
        cnt = 0;
        dfs(1);
        if(cnt != n){
            printf("Network %d: DISCONNECTED\n\n",++test);
            continue;
        }
        k = 0;
        REP1(i, 1, n)
            k = max(k, bfs(i));
        printf("Network %d: %d\n\n",++test,k);
    }


    return 0;
}














