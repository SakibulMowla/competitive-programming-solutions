#include "stdio.h"
#include "string.h"
#define SZ 65

typedef long long ll;

ll dp[SZ][SZ];
char arr[SZ];

ll solve(ll start,ll end)
{
    ll &ret = dp[start][end];
    if(ret != -1) return ret;

    if(start == end) return ret = 1LL;
    if(start > end)return ret = 0LL;

    if(arr[start] == arr[end])
        ret = solve(start+1, end) + solve(start, end-1) + 1;
    else
        ret = solve(start+1, end) + solve(start, end-1) - solve(start+1, end-1);

    return ret;
}

int main()
{
//    freopen("1.txt","r",stdin);
    ll i,j,n,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s",arr);
        n = strlen(arr);
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                dp[i][j] = -1;
        printf("%lld\n",solve(0,n-1));
    }

    return 0;
}
