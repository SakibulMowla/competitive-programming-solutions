#include "stdio.h"
#include "string.h"
#define SZ 55

template <class T> T max(T a,T b) { return a > b ? a : b; }
int dp[SZ][SZ][SZ];
char arr1[SZ] , arr2[SZ] , arr3[SZ];

int main()
{
    int t=0,test,i,j,k,len1,len2,len3;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%s %s %s",arr1,arr2,arr3);
        len1 = strlen(arr1) , len2 = strlen(arr2) , len3 = strlen(arr3);
        for(i=1;i<=len1;i++) for(j=1;j<=len2;j++) for(k=1;k<=len3;k++)
        {
            if(arr1[i-1] == arr2[j-1] && arr2[j-1] == arr3[k-1])
                dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
            else
                dp[i][j][k] = max(dp[i-1][j][k] , max(dp[i][j-1][k] , dp[i][j][k-1]));
        }
        printf("Case %d: %d\n",++t,dp[len1][len2][len3]);
    }

    return 0;
}
