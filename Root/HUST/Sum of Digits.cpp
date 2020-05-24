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

#define SZ 100010

ll dp[12][2], dp1[12][2];
int num[12], len;

void create(int n){
    len = -1;
    while(n){
        num[++len] = n%10;
        n /= 10;
    }
    return;
}

ll solve1(int indx, int flag){
    if(indx < 0) return 1LL;

    ll &ret = dp1[indx][flag];
    if(~ret) return ret;

    int i, lim, nflag;
    ret = 0;
    lim = flag ? num[indx] : 9;

    for(i=0; i<=lim; i++){
        if(i==lim && flag==1) nflag = 1;
        else nflag = 0;
        ret = ret + solve1(indx-1, nflag);
    }

    return ret;
}

ll solve(int indx, int flag){
    if(indx < 0) return 0LL;

    ll &ret = dp[indx][flag];
    if(~ret) return ret;

    int i, lim, nflag;
    ret = 0;
    lim = flag ? num[indx] : 9;

    for(i=0; i<=lim; i++){
        if(i==lim && flag==1) nflag = 1;
        else nflag = 0;
        ret = ret + i*solve1(indx-1, nflag) + solve(indx-1, nflag);
    }

    return ret;
}

ll solve(int n){
    if(n <= 0) return 0LL;
    mem(dp, -1);
    mem(dp1, -1);
    create(n);
    return solve(len, 1);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int a, b;

    while(scanf("%d %d",&a,&b) == 2){
        if(a == -1 && b == -1) break;
        printf("%lld\n",solve(b)-solve(a-1));
    }

    return 0;
}
















