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

#define SZ  25

ll dp[SZ][2][2];
ll sub_dp[SZ][2];
int num[SZ];
int len;

void init(ll n) {
    len = 0;
    while(n) {
        num[len++] = n%10;
        n /= 10;
    }
    reverse(num, num+len);
    return;
}

ll sub_solve(int indx, int flag) {
//    printf("%d %d\n", indx, flag);
    if(indx == len) return 1LL;

    ll &ret = sub_dp[indx][flag];
    if(ret != -1) return ret;

    ret = 0LL;
    int lim = flag ? num[indx] : 9;

    for(int i = 0; i <= lim; i++) {
        ret += sub_solve(indx+1, (flag == 1) && (i == lim));
    }

    return ret;
}

ll solve(int indx, int flag, int four) {
//    printf("%d %d %d\n", indx, flag, four);
    if(indx == len) return 0LL;

    ll &ret = dp[indx][flag][four];
    if(ret != -1) return ret;

    ret = 0LL;
    int lim = flag ? num[indx] : 9;

    for(int i = 0; i <= lim; i++) {
        if((four == 1) && (i == 9)) ret += sub_solve(indx+1, (flag == 1) && (i == lim));
        else ret += solve(indx+1, (flag == 1) && (i == lim), (i==4));
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    ll n;

    scanf("%d", &t);

    while(t--) {
        scanf("%I64d", &n);

        mem(dp, -1);
        mem(sub_dp, -1);
        init(n);

        printf("%I64d\n", solve(0, 1, 0));
    }

    return 0;
}











