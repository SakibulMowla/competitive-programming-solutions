#include "stdio.h"
#include "string.h"
#include "iostream"
using namespace std;
#define SZ 100

int dp[SZ][SZ] , arr[SZ][SZ];

const int inf = 1<<28;

int main()
{
    int i,j,n;
    while(cin >> n)
    {
//        for(i=0;i<=n;i++) for(j=0;j<=n;j++) dp[i][j] = inf;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin >> arr[i][j];
                if(i == 1) dp[i][j] = dp[i][j-1] + arr[i][j];
                else if(j == 1) dp[i][j] = dp[i-1][j] + arr[i][j];
                else dp[i][j] = min(dp[i][j-1] , dp[i-1][j]) + arr[i][j];
            }
        }
        printf("%d\n",dp[n][n]);
    }

    return 0;
}
