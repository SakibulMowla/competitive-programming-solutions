#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "string"
#include "vector"
#include "set"
#include "queue"
#include "map"
#include "deque"
#include "iostream"
#include "algorithm"
#include "assert.h"
#include "bitset"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))
#define sz(a) (int)a.size()
#define clr(a) a.clear()
#define MP(a, b) make_pair(a, b)

#define SZ 100+10

const ll inf = 1e16;

ll dp[SZ][SZ];
ll arr[SZ];
int N;

ll solve(int n, int m)
{
    if(m == 0)
    {
        if(n == N) return 0LL;
        return inf;
    }
    if(n == N) return inf;

    ll &ret = dp[n][m];
    if(ret != -1) return ret;

    ret = inf;

    for(int i=n; i<N; i++)
        ret = min(ret, arr[i]-arr[n] + solve(i+1, m-1));

    return ret;
}

int main()
{
    #ifdef PGD_LAB
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif

    int i, t, n, m, test=0;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);
        N = n;

        for(i=0; i<n; i++)
            scanf("%lld",&arr[i]);

        memset(dp, -1, sizeof(dp));
        sort(arr, arr+N);

        printf("Case #%d: %lld\n",++test, solve(0, m));
    }


    return 0;
}






