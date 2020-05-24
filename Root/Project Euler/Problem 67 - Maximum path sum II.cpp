#include "stdio.h"
#include "string.h"
#include "iostream"
using namespace std;
#define SZ 110

typedef long long ll;
ll dp[SZ][SZ] , arr[SZ][SZ];

int main()
{
    ll i,j,k,n;
    while(cin >> n)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                cin >> arr[i][j];
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j-1]) + arr[i][j];
            }
            k = 0;
            if(i == n)
                for(i=1;i<=n;i++)
                    k = max(k , dp[n][i]);
        }
        printf("%lld\n",k);
    }

    return 0;
}
