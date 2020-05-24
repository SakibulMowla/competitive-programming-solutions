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
const ll mod = 1000000007LL;

#define SZ 2010

ll dp[SZ][SZ];
int n, k;

ll solve(int indx, int val){
//    printf("%d %d\n",indx,val);
    if(indx == k-1) return 1LL;
    ll &ret = dp[indx][val];
    if(ret != -1) return ret;

    ret = 0LL;
    int i;
    for(i=1; val*i<=n; i++)
        ret = (ret + solve(indx+1, val*i)) % mod;

    return ret;
}

ll dp1[SZ][SZ];

ll solve1(){
    int i, j, p;
    ll res = 0LL;

    mem(dp1, 0);
    for(i=1; i<=n; i++)
        dp1[1][i] = 1LL;

    for(i=1; i<=k-1; i++)
        for(j=1; j<=n; j++)
            if(dp1[i][j])
                for(p=j; p<=n; p+=j){
                    dp1[i+1][p] = dp1[i+1][p] + dp1[i][j];
                    if(dp1[i+1][p] >= mod) dp1[i+1][p] -= mod;
                }

    for(i=1; i<=n; i++){
        res = res + dp1[k][i];
        if(res >= mod)
            res -= mod;
    }

    return res;
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    int i;
    ll res;

    while(scanf("%d %d",&n,&k) == 2){
//        mem(dp, -1);
//        res = 0LL;
//        for(i=1; i<=n; i++)
//            res = (res + solve(0, i)) % mod;
//        printf("%I64d\n",res);
        printf("%I64d\n",solve1());
    }


    return 0;
}













