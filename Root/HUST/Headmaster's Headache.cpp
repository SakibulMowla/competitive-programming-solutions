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
const int inf = 1e8;
const ll mod = 1LL;

#define SZ 110

int three[12];
int cost[SZ];
vector <int> sub[SZ];
int N, S;
int dp[SZ][7000];

int check(int mask, int pos){
    return (mask/three[pos]) % 3;
}

int Set(int mask, int pos, int val){
    mask -= (val-1) * three[pos];
    mask += val * three[pos];
    return mask;
}

void init(){
    three[0] = 1;
    int i;
    for(i=1;i<=10;i++) three[i] = 3 * three[i-1];
}

int solve(int indx, int mask){
    if(indx == N){
        if(mask == three[S]-1) return 0;
        return inf;
    }

    int &ret = dp[indx][mask];
    if(ret != -1) return ret;

    int tmp, i, k, j, bit;

    ret = solve(indx+1, mask);

    tmp = mask;
    k = sz(sub[indx]);
    REP(i, k){
        j = sub[indx][i];
        bit = check(mask, j);
        if(bit == 0) tmp = Set(tmp, j, 1);
        else if(bit == 1) tmp = Set(tmp, j, 2);
    }

    ret = min(ret, cost[indx] + solve(indx+1, tmp));

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    init();

    int s, m, n, i, j, k, ans, mask;
    char arr[10000], *ss;

    while(scanf("%d %d %d",&s,&m,&n) == 3){
        if(s==0) break;

        ans = 0;
        mask = 0;
        N = n;
        S = s;

        REP(i, m){
            scanf(" %[^\n]",arr);
            ss = strtok(arr," ");
            ans += atoi(ss);
            ss = strtok(NULL, " ");
            while(ss != NULL){
                j = atoi(ss) - 1;
                k = check(mask, j);
                if(k == 0) mask = Set(mask, j, 1);
                else if(k == 1) mask = Set(mask, j, 2);
                ss = strtok(NULL, " ");
            }
        }

        REP(i, n) clr(sub[i]);

        REP(i, n){
            scanf(" %[^\n]",arr);
            ss = strtok(arr," ");
            cost[i] = atoi(ss);
            ss = strtok(NULL, " ");
            while(ss != NULL){
                sub[i].pb( atoi(ss) - 1 );
                ss = strtok(NULL, " ");
            }
        }

        REP1(i, 0, n) REP1(j, 0, three[s]) dp[i][j] = -1;

        printf("%d\n",ans+solve(0, mask));
    }


    return 0;
}
















