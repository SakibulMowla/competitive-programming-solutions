#include "stdio.h"

#define SZ 10010

const int inf = 1<<28;
int min(int a,int b)
{
    return a < b ? a : b;
}
int dp[SZ];

int main()
{
    int i,j;
    for(i=1;i<SZ;i++) dp[i] = inf;

    dp[0] = 0;
    for(i=1; i*i<SZ; i++)
        for( j=i*i , dp[j] = 1; j<SZ; j++)
            dp[j] = min(dp[j] , 1 + dp[j-i*i]);

    scanf("%d",&j);
    while(j--)
    {
        scanf("%d",&i);
        printf("%d\n",dp[i]);
    }

    return 0;
}
