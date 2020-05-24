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

#define SZ 35

int ideal[SZ], num[SZ];

void pre(int idl){
    int i=0;
    mem(ideal, 0);
    while(idl){
        ideal[i++] = idl&1;
        idl >>= 1;
    }
}

ll dp[SZ][2][SZ][SZ][3][7], dp1[SZ][2][SZ][SZ][3][7];

///koyta
ll solve1(int indx, int flag, int one, int differ, int three, int seven){
    if(differ<0 || one <0) return 0LL;
    if(indx < 0) {
//        printf("ts = %d %d\n",three,seven);
        return (three==0) && (seven!=0);
    }

    ll &ret = dp1[indx][flag][one][differ][three][seven];
    if(~ret) return ret;

    int i, nflag, lim;
    lim = flag ? num[indx] : 1;
    ret = 0LL;

    for(i=0; i<=lim; i++){
        if(flag && i==lim) nflag = 1;
        else nflag = 0;
        ret += solve1(indx-1, nflag, one-(i==1), differ-(i!=ideal[indx]), (three+i*(1<<indx))%3, (seven+i*(1<<indx))%7);
    }

    return ret;
}

///sum
ll solve(int indx, int flag, int one, int differ, int three, int seven){
//    printf("%d %d\n",indx,flag);
    if(differ<0 || one <0) return 0LL;
    if(indx < 0) return 0;

    ll &ret = dp[indx][flag][one][differ][three][seven];
    if(~ret) return ret;

    int i, nflag, lim;
    lim = flag ? num[indx] : 1;
    ret = 0LL;

    for(i=0; i<=lim; i++){
        if(flag && i==lim) nflag = 1;
        else nflag = 0;
        ret += i ? (1<<indx) * solve1(indx-1, nflag, one-(i==1), differ-(i!=ideal[indx]), (three+i*(1<<indx))%3, (seven+i*(1<<indx))%7) : 0LL;
        ret += solve(indx-1, nflag, one-(i==1), differ-(i!=ideal[indx]), (three+i*(1<<indx))%3, (seven+i*(1<<indx))%7);
    }

    return ret;
}

ll solve(int n, int maxone, int k){
    if(n < 0) return 0LL;

//    printf("N = %d\n",n);

    int i=0;
    mem(num, 0);
    while(n){
        num[i++] = n&1;
        n >>= 1;
    }

    mem(dp, -1);
    mem(dp1, -1);

    return solve(34, 1, maxone, k, 0, 0);
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    int test=0, t, strt, endd, maxone, k, idl;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d %d %d %d",&strt,&endd,&maxone,&idl,&k);

        pre(idl);
        maxone = min(maxone, 32);
        k = min(k, 32);

        printf("Case %d: %lld\n",++test,solve(endd, maxone, k)-solve(strt-1, maxone, k));
    }


    return 0;
}













