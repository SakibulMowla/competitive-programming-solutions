#include "stdio.h"
#include "string.h"

#define MAX 1010

int min(int a,int b)
{
    return a < b ? a : b;
}

int dp[MAX][MAX];
char arr1[MAX] , arr2[MAX];

int main()
{
    int i,j,k,len1,len2;

    while(scanf("%d",&len1) == 1)
    {
        scanf("%s %d %s",arr1+1,&len2,arr2+1);

        for(i=1;i<=len1;++i)dp[i][0] = i;
        for(j=1;j<=len2;++j)dp[0][j] = j;
        dp[0][0] = 0;

        for(i=1;i<=len1;i++)
            for(j=1;j<=len2;j++)
            {
                if(arr1[i] == arr2[j])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1])) + 1;
            }

        printf("%d\n",dp[len1][len2]);
    }

    return 0;
}
