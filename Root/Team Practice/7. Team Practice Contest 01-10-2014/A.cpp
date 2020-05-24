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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010

bool isInQueue[SZ];
int lastTime[SZ];
int arrow[SZ];
set <pii> ms;
int n, m, c;

int calc(int lim) {
    int tym = 0, ans = 0;

    mem(isInQueue, 0);
    ms.clear();

    for(int i = 0; i < m; i++) {
        if(isInQueue [arrow[i]]) {
            ms.erase( MP(lastTime[ arrow[i] ], arrow[i]) );
            lastTime[ arrow[i] ] = ++tym;
            ms.insert( MP(lastTime[ arrow[i] ], arrow[i]) );
            continue;
        }
        else {
            ans++;
            if(ans > c) return inf;

            if(sz(ms) < lim) {
                lastTime[ arrow[i] ] = ++tym;
                ms.insert( MP(tym, arrow[i]) );
                isInQueue[ arrow[i] ] = 1;
            }
            else {
                isInQueue[ ms.begin()->second ] = 0;
                ms.erase(ms.begin());
                lastTime[ arrow[i] ] = ++tym;
                ms.insert( MP(tym, arrow[i]) );
                isInQueue[ arrow[i] ] = 1;
            }
        }
    }

    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &m, &c);

        for(int i = 0; i < m; i++)
            scanf("%d", &arrow[i]);

        int lo, hi, mid, ans = inf;

        lo = 1;
        hi = n;

        while(lo <= hi) {
            mid = (lo + hi) >> 1;
            int k = calc(mid);

//            printf("------------ %d %d \n",mid,k);

            if(k <= c) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        if(ans == inf) ans = -1;
        printf("%d\n", ans);
    }

    return 0;
}













