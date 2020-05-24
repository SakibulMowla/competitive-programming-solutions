#include "stdio.h"
#include "string.h"
#include "iostream"
using namespace std;
#define SZ 1010
#define SZ1 10010

typedef long long ll;

ll dp[SZ][SZ1], cumu[SZ], arr[SZ], N, L;

ll solve(ll indx,ll first)
{
    if(indx == N+1)
        return 0;
    ll &ret = dp[indx][first];
    if(ret != -1)
        return ret;
    ll second = cumu[indx] - first;
    ret = 0;
    if(first+arr[indx] <= L)
        ret = max(ret, 1+solve(indx+1,first+arr[indx]));
    if(second <= L)
        ret = max(ret, 1+solve(indx+1,first));
    return ret;
}

void print(ll indx,ll first)
{
    if(indx == N+1)
        return;
    ll second = cumu[indx] - first;
    if(arr[indx]+first <= L && dp[indx+1][arr[indx]+first] >= dp[indx+1][first])
        printf("port\n"), print(indx+1, first+arr[indx]);
    else if(second <= L && dp[indx+1][arr[indx]+first] <= dp[indx+1][first])
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
        for(i=0;i<=N;i++)
            for(j=0;j<=L;j++)
                dp[i][j] = -1;
        printf("%lld\n",solve(1, 0));
        print(1, 0);
        if(t) printf("\n");
    }

    return 0;
}
