#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

#define SZ 110
#define SD(a) scanf("%d",&a)
#define FOR(i,n) for(i=0;i<n;i++)

const int inf = 1<<28;

int dp[SZ][SZ] , input[SZ][SZ];

int main()
{
    int test,i,j,n;
    scanf("%d",&test);
    while(test--)
    {
        SD(n);
        FOR(i,n) FOR(j,n)
        {
            SD(input[i][j]);
            dp[i][j] = (i+j == 0) ? 0 : -inf;
            if(i > 0)
            {
                dp[i][j] = max(dp[i][j] , input[i][j] + dp[i-1][j]);
            }
            if(j > 0)
            {
                dp[i][j] = max(dp[i][j] , input[i][j] + dp[i][j-1]);
            }
        }

        if(dp[n-1][n-1] < 0) printf("Bad Judges\n");
        else printf("%.6lf\n",(double)dp[n-1][n-1] / (2*n - 3));
    }

    return 0;
}
