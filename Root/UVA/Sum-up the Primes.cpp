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

#define SZ 1010

bool arr[SZ];
int prime[SZ];
int N, T;

void sieve(){
    int i, j;
    prime[0] = 2;
    N = 1;
    for(i=3;i<300;i+=2){
        if(arr[i] ==0){
            prime[N++] = i;
            for(j=i*i;j<300;j+=i+i)
                arr[j] = 1;
        }
    }
}

bool comp(int a, int b){
    char s1[5], s2[5];
    string ss1, ss2;
    sprintf(s1,"%d",a);
    sprintf(s2,"%d",b);
    ss1 = s1;
    ss2 = s2;
    return ss1<ss2;
}

int dp[18][70][1010];

int solve(int t, int n, int val){
    int &ret = dp[t][n][val];
    if(ret != -1) return ret;

    if(t == T) return ret = (val==0);
    if(val==0 || n==N || t>T) return ret = 0;

    ret = 0;
    if((prime[n]&1) && val-(prime[n]<<1)>=0 && t+2<=T) ret = solve(t+2, n+1, val-(prime[n]<<1));
    if(ret == 1) return ret;
    if(val-prime[n] >= 0) ret = solve(t+1, n+1, val-prime[n]);
    if(ret == 1) return ret;
    ret = solve(t, n+1, val);

    return ret;
}

void path_print(int t, int n, int val){
//    printf("t = %d\n",t);
    if(!val) return;
    if((prime[n]&1) && val-(prime[n]<<1)>=0 && t+2<=T && dp[t+2][n+1][val-(prime[n]<<1)]==1){
        if(t) printf("+");
        printf("%d+%d",prime[n],prime[n]);
        return path_print(t+2, n+1, val-(prime[n]<<1));
    }
    if(val-prime[n] >= 0 && dp[t+1][n+1][val-prime[n]]==1){
        if(t)printf("+");
        printf("%d",prime[n]);
        return path_print(t+1, n+1, val-prime[n]);
    }
    return path_print(t, n+1, val);
}

int main() {
    #if defined JESI
//        freopen("2.txt", "w", stdout);
    #endif

    sieve();
    sort(prime, prime+N, comp);
    int test=0, n, t, i, j, k;

    while(scanf("%d %d",&n,&t) == 2){
        if(n==0 && t==0) break;
        T = t;
        for(i=0;i<=t;i++) for(j=0;j<=N;j++) for(k=0;k<=n;k++) dp[i][j][k] = -1;
        printf("CASE %d:\n",++test);
        if(solve(0, 0, n)){
            path_print(0, 0, n);
            puts("");
        }
        else puts("No Solution.");
    }

    return 0;
}
















