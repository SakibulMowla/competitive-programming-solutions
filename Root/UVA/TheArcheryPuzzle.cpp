#include <bits/stdc++.h>

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
const int inf = 100000;
const ll mod = 1LL;

#define SZ 55
#define SZ1 310

int dp[SZ][SZ1];
int arr[SZ];

int solve(int n, int s) {
    int &ret = dp[n][s];
    if(~ret) return ret;

    if(s == 0) return ret = 0;
    if(n == 0) return ret = inf;

    ret = inf;
    if(s - arr[n] >= 0) ret = 1 + solve(n, s-arr[n]);
    ret = min(ret, solve(n-1, s));

    return ret;
}

void path(int n, int s) {
    if(s == 0) return;
    if(s - arr[n] >= 0 && dp[n][s] == 1 + dp[n][s-arr[n]]) {
        printf(" %d", arr[n]);
        return path(n, s - arr[n]);
    }
    return path(n-1, s);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, s;
        scanf("%d %d", &n, &s);

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i+1]);
        }

        mem(dp, -1);
        int k = solve(n, s);

        printf("Case %d:", cs+1);
        if(k < inf) {
            printf(" [%d]", k);
            path(n, s);
        } else {
            printf(" impossible");
        }
        puts("");
    }

    return 0;
}













