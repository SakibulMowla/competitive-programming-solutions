#include "stdio.h"
#define SZ 305
typedef long long ll;
int min(int a,int b) { return a < b ? a : b; }
ll dp[SZ][SZ] , sum[SZ][SZ];

int main()
{
    ll i,j,k,len;
    char arr[100];
    dp[0][0] = 1;

    for(i=1;i<SZ;i++)
        for(j=i;j<SZ;j++)
            for(k=1;k<SZ;k++)
                dp[j][k] += dp[j-i][k-1];
    for(i=0;i<SZ;i++) sum[0][i] = dp[0][i];
    for(i=1;i<SZ;i++)
        for(j=1;j<SZ;j++)
            sum[i][j] += dp[i][j] + sum[i][j-1];

    while(scanf(" %[^\n]",arr) == 1)
    {
        len = sscanf(arr,"%lld %lld %lld",&i,&j,&k);
        if(len == 1) printf("%lld\n",sum[i][i]);
        else if(len == 2) printf("%lld\n",sum[i][ min(i,j) ]);
        else if(j <= i) printf("%lld\n",sum[i][ min(i,k) ] - sum[i][j] + dp[i][j]);
        else printf("0\n");
    }

    return 0;
}
