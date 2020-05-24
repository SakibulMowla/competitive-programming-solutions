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
ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000007LL;

#define SZ  100010

bool arr[SZ];
vector <int> prime;
int cnt[SZ];

void sieve(){
    int i, j, k;

    k = sqrt(SZ);

    for(i=3; i<=k; i+=2)
        if(!arr[i])
            for(j=i*i; j<SZ; j+= i+i)
                arr[j] = 1;

    prime.pb(2);
    for(i=3; i<SZ; i+=2)
        if(!arr[i])
            prime.pb(i);
}

void factorize(int n){
    int i, j, k;

    k = sz(prime);

    for(i=0; i<k && prime[i]*prime[i]<=n; i++){
        if(n%prime[i] == 0){
            j = 0;
            while(n%prime[i] == 0){
                n /= prime[i];
                j++;
            }
            cnt[ prime[i] ] = max(j, cnt[ prime[i] ]);
        }
    }

    if(n != 1){
        cnt[n] = max(1, cnt[n]);
    }

    return;
}

bool vis[SZ];
int adj[SZ];
int NODES;

void dfs(int u){
    NODES++;
    vis[u] = 1;

    int i, j;

    if(vis[ adj[u] ] == 0){
        dfs( adj[u] );
    }

    return;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    sieve();

    int t, n, i, j, k;
    ll ans;

    RD(t);

    while(t--){
        mem(vis, 0);
        mem(cnt, 0);
        RD(n);

        REP(i, n){
            RD(j);
            adj[i+1] = j;
        }

        REP1(i, 1, n){
            if(vis[i] == 0){
                NODES = 0;
                dfs(i);
//                printf("i = %d nodes = %d\n",i,NODES);
                factorize(NODES);
            }
        }

        k = sz(prime);

        ans = 1LL;

//        printf("cnt3 = %d\n",cnt[3]);
//        printf("cnt2 = %d\n",cnt[2]);

        REP(i, k){
            ans = (ans * BigMod(prime[i], cnt[ prime[i] ], mod)) % mod;
        }

        PR(ans);
    }

    return 0;
}













