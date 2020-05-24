#include "stdio.h"
#define SZ 310
typedef long long ll;
template <class T> T max(T a,T b) { return a > b ? a : b; }
template <class T> T min(T a,T b) { return a < b ? a : b; }
ll dp[SZ][SZ] , sum[SZ][SZ];

int main()
{
    ll i,j,k,n,m;
    char arr[110];
    dp[0][0] = 1;
    for(i=1;i<=300ll;i++)
        for(j=i;j<=300ll;j++)
            for(k=1;k<=300ll;k++)
                dp[j][k] = dp[j][k] + dp[j-i][k-1];
    for(i=0;i<=300ll;i++) sum[0][i] = dp[0][i];
    for(i=1;i<=300ll;i++)
        for(j=1;j<=300ll;j++)
            sum[i][j] = dp[i][j] + sum[i][j-1];
//    printf("%lld\n",dp[6][6]);
//    printf("%lld\n",dp[6][3]);
    while(scanf(" %[^\n]",arr) == 1)
    {
        n = sscanf(arr,"%lld %lld %lld",&i,&j,&k);
        if(n == 1) printf("%lld\n",sum[i][i]);
        else if(n == 2) printf("%lld\n",sum[i][min(i,j)]);
        else if(n == 3 && j<=i) printf("%lld\n",sum[min(i,300ll)][min(300ll,k)]-sum[min(i,300ll)][min(300ll,j)]+dp[min(i,300ll)][min(300ll,j)]);
        else printf("0\n");
    }

    return 0;
}
