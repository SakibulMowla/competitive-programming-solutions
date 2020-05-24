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

#define SZ  22

int debt[SZ][SZ];
int N;
bool visited[ (1 << 20) + 2 ];
vector <int> ans;

void solve(int mask, int cnt) {
    if(visited[mask]) return;
    visited[mask] = 1;

    int i, j, tmp;

    if(cnt == 1)
        for(i = 0; i < N; i++)
            if(mask & (1<<i)) {
                ans.pb(i);
                return;
            }

    for(i = 0; i < N; i++) if(mask & (1<<i)) {
        tmp = 0;

        for(j = 0; j < N; j++) {
            if(mask & (1<<j))
                tmp += debt[i][j];
        }

        if(tmp < 0)
            solve(mask & ~(1<<i), cnt-1);
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t, i, j, k;

    scanf("%d",&t);

    while(t--) {
        scanf("%d",&N);

        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++) {
                scanf("%d",&debt[i][j]);
                debt[i][j] = -debt[i][j];
            }

        k = (1 << N) - 1;
        memset(visited, 0, sizeof(bool)*(k+2));
        ans.clear();

        solve(k, N);
        sort(ans.begin(), ans.end());

        if(!(k = sz(ans))) printf("0\n");
        else {
            for(i = 0; i < k; i++) {
                if(i) printf(" ");
                printf("%d",ans[i]+1);
            }
            printf("\n");
        }
    }

    return 0;
}













