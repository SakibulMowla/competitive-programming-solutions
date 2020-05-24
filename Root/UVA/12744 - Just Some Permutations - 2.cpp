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
#include <time.h>

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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ 4782969+10

int three[20];

void pre() {
    three[0] = 1;
    for (int i = 1; i < 16; i++) {
        three[i] = 3 * three[i-1];
    }
    return;
}

int get_bit(int mask, int pos){
    return (mask / three[pos]) % 3;
}

int set_bit(int mask, int pos, int bit){
    int tmp = (mask / three[pos]) % 3;
    mask -= tmp * three[pos];
    mask += bit * three[pos];
    return mask;
}

ll dp[SZ];
int col[SZ];
int now;
int N;

ll solve (int pos, int mask, int lis) {
    ll &ret = dp[mask];
    if(col[mask] == now) return ret;
    if(pos == 0) return ret = (lis == 0);

    col[mask] = now;
    ret = 0LL;

    /// 0 -> Unused, 1 -> Used but not in LIS, 2 -> Used and in LIS

    for (int i = 0; i < N; i++) if(get_bit(mask, i) == 0) {
        bool f = 0;
        int tmp_mask = set_bit(mask, i, 2);
        int tmp_lis = lis;

        for (int j = i+1; j < N; j++) if(get_bit(mask, j) == 2) {
            f = 1;
            tmp_mask = set_bit(tmp_mask, j, 1);
            break;
        }

        if(!f) tmp_lis--;
        if(tmp_lis >= 0)
            ret += solve(pos-1, tmp_mask, tmp_lis);
    }

    return ret;
}

void path (int pos, int mask, int lis, ll k) {
    if(pos == 0) return;

    for (int i = 0; i < N; i++) if(get_bit(mask, i) == 0) {
        bool f = 0;
        int tmp_mask = set_bit(mask, i, 2);
        int tmp_lis = lis;

        for (int j = i+1; j < N; j++) if(get_bit(mask, j) == 2) {
            f = 1;
            tmp_mask = set_bit(tmp_mask, j, 1);
            break;
        }

        if(!f) tmp_lis--;
        if(tmp_lis >= 0) {
            if(k > dp[tmp_mask])
                k -= dp[tmp_mask];
            else {
                printf(" %d", i+1);
                return path(pos-1, tmp_mask, tmp_lis, k);
            }
        }
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    pre();

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, k, l;
        scanf("%d %d %d", &n, &l, &k);

        N = n;
        now++;
        ll ans = solve(n, 0, l);

        printf("Case %d:", cs+1);
        if(ans < k) printf(" -1");
        else path(n, 0, l, (ll)k);
        printf("\n");
    }

    return 0;
}












