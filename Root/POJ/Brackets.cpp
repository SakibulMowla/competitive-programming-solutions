#include "stdio.h"
#include "string.h"
#include "iostream"
using namespace std;

#define SZ 110;

int dp[SZ][SZ];

bool equal(char c1, char c2)
{
    return (c1=='(' && c2==')') || (c1=='[' && c2==']');
}

int main()
{
    int i, j, k, n;
    char arr[110];

    while(scanf("%s",arr+1) == 1)
    {
        n = strlen(arr+1);
        memset(dp, 0, sizeof(dp));
        for(i=1; i<=n; i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(equal(arr[i], arr[j]))
                    dp[i][j] = max(dp[i][j], 2+dp[i])
                for(k=i;k<j;k++)
                {

                }
            }
        }
    }

    return 0;
}
