#include "stdio.h"
#include "map"
#include "string.h"
#include "iostream"
using namespace std;
#define SZ 1010
#define SZ1 10010
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<ll,ll>pii;

map<pii, ll> dp;

ll cumu[SZ], arr[SZ], N, L;

ll solve(ll indx,ll first)
{
    if(indx == N+1)
        return 0;
    if(dp.find(MP(indx,first)) != dp.end())
        return dp[MP(indx, first)];
    ll ret = 0;
    ll second = cumu[indx] - first;
    if(first+arr[indx] <= L)
        ret = max(ret, 1+solve(indx+1,first+arr[indx]));
    if(second <= L)
        ret = max(ret, 1+solve(indx+1,first));
    return dp[MP(indx,first)] = ret;
}

void print(ll indx,ll first)
{
    if(indx == N+1)
        return;
    ll second = cumu[indx] - first;
    ll one, two;
    one = two = -1;
    if(dp.find(MP(indx+1,arr[indx]+first)) != dp.end())
        one = dp[MP(indx+1,arr[indx]+first)];
    if(dp.find(MP(indx+1,first)) != dp.end())
        two = dp[MP(indx+1,first)];
    if(arr[indx]+first <= L && one >= two)
        printf("port\n"), print(indx+1, first+arr[indx]);
    else if(second <= L && one <= two)
        printf("starboard\n"), print(indx+1, first);
}

int main()
{
    ll t, i, j, k, n;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&L);
        L *= 100;
        N = 0;
        while(scanf("%lld",&arr[++N]) == 1 && arr[N])
        {
            cumu[N] = arr[N] + cumu[N-1];
        }
        N--;
        dp.clear();
        printf("%lld\n",solve(1, 0));
        print(1, 0);
        if(t) printf("\n");
    }

    return 0;
}
