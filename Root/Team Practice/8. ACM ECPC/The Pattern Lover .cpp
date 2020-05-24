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
#include <bitset>


using namespace  std;

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
const int inf = 1;
const ll mod = 1LL;

#define SZ  10010

int cnt[8];
int day[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test=0,t;

    scanf("%d", &t);
    while(t--)
    {
        mem(cnt, 0);

        int n, maxim = 0;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &day[i]);
//            day[i]--;
//            maxim = max(maxim, day);
//            cnt[day % 7]++;
        }

        sort(day, day+n);

        for(int i = n-1; i >= 0; i--)
        {
            day[i] -= day[0];
            cnt[ day[i]%7 ]++;
        }

        int lim = 1<<7;
        int ans = 1e9;

        for(int mask = 0; mask < lim; mask++)
        {
            int tmp = 0;
            for(int i = 0; i < 7; i++)
                if(mask & (1<<i))
                {
                    int need = (day[n-1] - i + 7) / 7;
//                    printf("i = %d need = %d\n", i, need);
                    tmp += need - cnt[i];
                }
                else
                    tmp += cnt[i];

            ans = min(ans, tmp);
        }

        printf("Case %d: %d\n", ++test, ans);
    }

    return 0;
}












