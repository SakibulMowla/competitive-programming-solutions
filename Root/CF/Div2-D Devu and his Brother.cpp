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
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010

ll a[SZ], b[SZ];
ll csum_a[SZ], csum_b[SZ];

int N, M;

ll bs_a(int val){
    int lo, hi, mid, ans;
    ll res = 0;

    ans = -1;
    lo = 1;
    hi = N;

    while(lo <= hi){
        mid = (lo + hi) >> 1;
        if(a[mid] <= val){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    if(ans != -1){
        res = (ll)val * (ll)ans - csum_a[ans];
    }

    return res;
}

ll bs_b(int val){
    int lo, hi, mid, ans;
    ll res = 0;

    ans = -1;
    lo = 1;
    hi = M;

    while(lo <= hi){
        mid = (lo + hi) >> 1;
        if(b[mid] >= val){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    if(ans != -1){
        res = csum_b[M] - csum_b[ans-1] - (ll)(M-ans+1) * (ll)val;
    }

    return res;
}

ll ternary(){
    int i, j, k, lo, hi, m1, m2;
    ll tmp1, tmp2, ans;

    k = 200;
    lo = 1;
    hi = 1e9;
    ans = 1e18;

    while(k--){
        m1 = (2*lo + hi) / 3;
        m2 = (lo + 2*hi) / 3;
        tmp1 = bs_a(m1) + bs_b(m1);
        tmp2 = bs_a(m2) + bs_b(m2);
        if(tmp1 < tmp2){
            hi = m2;
            ans = min(ans, tmp1);
        }
        else{
            lo = m1;
            ans = min(ans, tmp2);
        }
    }

    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("4.txt", "w", stdout);
    #endif

    int i, j, k;
    ll ans;

    while(scanf("%d %d",&N,&M) == 2){

        REP1(i, 1, N) RD(a[i]);
        REP1(i, 1, M) RD(b[i]);

        stable_sort(a+1, a+N+1);
        stable_sort(b+1, b+M+1);

        REP1(i, 1, N) csum_a[i] = csum_a[i-1] + a[i];
        REP1(i, 1, M) csum_b[i] = csum_b[i-1] + b[i];



        ans = 1e18;

        REP1(i, 1, N) ans = min(ans, bs_a(a[i])+bs_b(a[i]));
        REP1(i, 1, M) ans = min(ans, bs_a(b[i])+bs_b(b[i]));

        PR(ans);

        #if defined JESI
            puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        #endif
    }

    return 0;
}


/*
3 4
6 6 6
8 8 8 8
3 4
99999999 99999999 99999999
100000000 100000000 100000000 100000000
*/




