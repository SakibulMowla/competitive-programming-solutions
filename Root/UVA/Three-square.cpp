#include <stdio.h>
#include <string.h>
#include <math.h>
#define SZ 50000

int dp[SZ+1][3];

int main()
{
    int i,j,k,sum;
    for(i=0; i*i<=SZ; i++)
        for(j=i; i*i + j*j<=SZ; j++)
            for(k=j; i*i + j*j +k*k<=SZ; k++)
            {
                sum = i*i + j*j +k*k;
                if(!dp[sum][0] && !dp[sum][1] && !dp[sum][2])
                    dp[sum][0] = i , dp[sum][1] = j ,dp[sum][2] = k ;
            }
    int test,num;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&num);
        if(!dp[num][0] && !dp[num][1] && !dp[num][2]) printf("-1\n");
        else printf("%d %d %d\n",dp[num][0],dp[num][1],dp[num][2]);
    }
    return 0;
}
