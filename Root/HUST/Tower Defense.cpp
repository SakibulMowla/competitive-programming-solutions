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
ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

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
const ll mod = ((1e9)+7);

#define SZ 50

ll nCr[SZ];

void pre(){
    int i;
    for(i=1; i<=200; i++)
        nCr[i] = (i*(i-1)) / 2;
}

ll dp[SZ][SZ][SZ][SZ];

ll solve(int row, int col, int p, int q){
    if(p+q == 0) return 1LL;
    if(row == 0 || col == 0) return 0LL;

    ll &ret = dp[row][col][p][q];
    if(~ret) return ret;

    ret = solve(row-1, col, p, q);
    if(q) ret = (ret + (col * solve(row-1, col-1, p, q-1)) % mod ) % mod;
    if(p){
        ret = (ret + (col * solve(row-1, col-1, p-1, q)) % mod) % mod;
        if(col >= 2 && p >= 2) ret = (ret + (nCr[col] * solve(row-1, col-2, p-2, q)) % mod) % mod;
        if(row >= 2 && p >= 2) ret = (ret + ( (row-1) * col * solve(row-2, col-1, p-2, q)) % mod ) % mod;
    }

    return ret;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("3.txt", "w", stdout);
    #endif

    pre();
    mem(dp, -1);

    int row, col, p, q, t, i, j;
    ll ans;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d %d %d",&row,&col,&p,&q);

        ans = 0LL;
        for(i=0; i<=p; i++) for(j=0; j<=q; j++) if(i+j) ans = (ans + solve(row, col, i, j)) % mod;

        printf("%lld\n",ans);

//        printf("%lld %lld\n",solve(row, col, 1, 0),solve(row, col, 2, 0));
    }

    return 0;
}
















