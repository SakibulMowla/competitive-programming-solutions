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

int a, b, k;
int arr_a[SZ], arr_b[SZ], arr_k[SZ];

void d2b_a(){
    int i = 0;
    while(a){
        arr_a[i++] = a % 2;
        a /= 2;
    }
}

void d2b_b(){
    int i = 0;
    while(b){
        arr_b[i++] = b % 2;
        b /= 2;
    }
}

void d2b_k(){
    int i = 0;
    while(k){
        arr_k[i++] = k % 2;
        k /= 2;
    }
}

ll dp[100][3][3][3];

ll solve(int indx, int flag_a, int flag_b, int flag_k){
    if(indx == -1){
        if(flag_a==0 && flag_b==0 && flag_k==0) return 1LL;
        return 0LL;
    }

    ll &ret = dp[indx][flag_a][flag_b][flag_k];
    if(ret != -1) return ret;

    int i, j, l, lim_a, lim_b, lim_k, nflag_a, nflag_b, nflag_k;
    ret = 0LL;

    lim_a = flag_a ? arr_a[indx] : 1;
    lim_b = flag_b ? arr_b[indx] : 1;
    lim_k = flag_k ? arr_k[indx] : 1;

    for(i=0; i<=lim_a; i++){
        for(j=0; j<=lim_b; j++){
            l = i&j;
            {
                if(i==lim_a && flag_a==1) nflag_a = 1;
                else nflag_a = 0;
                if(j==lim_b && flag_b==1) nflag_b = 1;
                else nflag_b = 0;
                if(l==lim_k && flag_k==1) nflag_k = 1;
                else nflag_k = 0;

                if(l > lim_k) continue;

                ret += solve(indx-1, nflag_a, nflag_b, nflag_k);
            }
        }
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("3.txt", "w", stdout);
    #endif

    int test=0, t;

    RD(t);

    while(t--){
        scanf("%d %d %d",&a,&b,&k);
        mem(arr_a, 0);
        mem(arr_b, 0);
        mem(arr_k, 0);
        d2b_a();
        d2b_b();
        d2b_k();

        mem(dp, -1);

        printf("Case #%d: %lld\n",++test, solve(60, 1, 1, 1));
    }

    return 0;
}













