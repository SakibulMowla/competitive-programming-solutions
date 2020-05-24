#include "stdio.h"
#include "string.h"
#include "iostream"
using namespace std;

#define SZ 1010

char arr1[SZ], arr2[SZ];
int dp[SZ][SZ];


int main()
{
    int i, j, len1, len2;

    while(scanf("%s %s",arr1,arr2)!=EOF)
    {
        len1 = strlen(arr1);
        len2 = strlen(arr2);

        for(i=1;i<=len1;i++)
            for(j=1;j<=len2;j++)
            {
                if(arr1[i-1] == arr2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        printf("%d\n",dp[len1][len2]);
    }

    return 0;
}
