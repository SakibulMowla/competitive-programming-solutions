using namespace std;

#include "stdio.h"
#include "string.h"
#include "iostream"

#define MAX 2010

int dp[MAX][MAX];
char arr1[MAX] , arr2[MAX];

int main()
{
    int i, j, t ,len1 , len2;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%s",arr1+1);
        scanf("%s",arr2+1);

        len1 = strlen(arr1+1);
        len2 = strlen(arr2+1);

        for(i=0;i<=len1;i++) dp[i][0] = i;
        for(i=0;i<=len2;i++) dp[0][i] = i;

        for(i=1;i<=len1;i++)
            for(j=1;j<=len2;j++)
            {
                if(arr1[i] == arr2[j])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min( dp[i-1][j-1] , min( dp[i-1][j] , dp[i][j-1] ) );
            }

        printf("%d\n", dp[len1][len2]);
    }

    return 0;
}
