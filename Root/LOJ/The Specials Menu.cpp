#include "stdio.h"
#include "string.h"
#define SZ 65

#define ll long long
ll dp[SZ][SZ];
char arr[SZ];

ll solve(ll start,ll end)
{
    if(start > end) return 0ll;
    if(start == end) return 1ll;
    ll ret = dp[start][end];
    if(ret != -1) return ret;
    if(arr[start] == arr[end])
        ret = 1 + solve(1+start,end) + solve(start,end-1);
    else ret = solve(1+start,end) + solve(start,end-1) - solve(start+1,end-1);
    return dp[start][end] = ret;
}

int main()
{
    ll t=0,test,i,j,n;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%s",arr);
        n = strlen(arr);
        for(i=0; i<n; i++) for(j=0; j<n; j++) dp[i][j] = -1;
        printf("Case %lld: %lld\n",++t,solve(0ll,n-1));
    }

    return 0;
}
