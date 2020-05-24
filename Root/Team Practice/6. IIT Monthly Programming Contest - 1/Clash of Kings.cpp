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

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

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
const int inf = 1e9;
const ll mod = 1LL;

#define SZ  210

int mat[SZ][SZ];

void init(int n) {
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) {
            if(i == j) mat[i][j] = 0;
            else mat[i][j] = inf;
        }
    return;
}

void floyd(int n) {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
    return;
}

int three[20];

void init(){
    three[0] = 1;
    for(int i = 1; i <= 15; i++)
        three[i] = 3 * three[i-1];
    return;
}

int get_bit(int mask, int pos){
    return (mask / three[pos]) % 3;
}

int set_bit(int mask, int pos, int bit){
    int tmp =(mask / three[pos]) % 3;
    mask -= tmp * three[pos];
    mask += bit * three[pos];
    return mask;
}

int city[20];

int dp[12][531441+10];
int K;

int solve(int pos, int mask) {
    if(pos == K) {
        vector <int> v1, v2;

        for(int j = 0; j < K; j++) {
            if(get_bit(mask, j) == 1)
                v1.pb(city[j]);
            else
                v2.pb(city[j]);
        }

        int sum = 0;
        for(int a = 0; a < sz(v1); a++) {
            for(int b = 0; b < sz(v2); b++) {
                sum += mat[ v1[a] ][ v2[b] ];
            }
        }
//        printf("%d %d\n", mask, sum);
        return sum;
    }

    int &ret = dp[pos][mask];
    if(ret != -1) return ret;

    if((pos%2) == 0) ret = 0;
    else ret = inf;

    for(int i = 0; i < K; i++) {
        if(get_bit(mask, i) == 0) {
            if((pos%2) == 0) ret = max(ret, solve(pos+1, set_bit(mask, i, 1)));
            else ret = min(ret, solve(pos+1, set_bit(mask, i, 2)));
        }
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    init();
//    printf("%d\n",three[12]);
    int n, m, k;

    while(scanf("%d %d %d", &n, &m, &k) == 3) {
        init(n);
        K = k;

        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            mat[u][v] = mat[v][u] = min(mat[u][v], w);
        }

        for(int i = 0; i < k; i++)
            scanf("%d", &city[i]);

        floyd(n);
        mem(dp, -1);

        printf("%d\n", solve(0, 0));
    }


    return 0;
}













