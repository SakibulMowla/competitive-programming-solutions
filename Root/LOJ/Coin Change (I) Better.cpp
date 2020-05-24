#include "stdio.h"

#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 55
#define SZ1 1010
#define SD(n) scanf("%d",&n)

int dp[SZ1] , A[SZ] , C[SZ];

int main()
{
    int t=0,test,n,target,i,j,k,tmp;
    SD(test);
    while(test--)
    {
        SD(n); SD(target);
        FOR(i,n) SD(A[i]);
        FOR(i,n) SD(C[i]);
        FOR(i,target+1) dp[i] = 0;
        dp[0] = 1;
        FOR(i,n)
        {
            for(j=target;j>=0;j--)
            {
                tmp = j;
                FOR(k,C[i])
                {
                    tmp += A[i];
                    if(tmp > target) break;
                    dp[tmp] = (dp[tmp] + dp[j]) % 100000007;
                }
            }
            for(int p=0;p<=9;p++) printf("%d %d\n",p,dp[p]);
            printf("\n");
        }
        printf("Case %d: %d\n",++t,dp[target]);
    }

    return 0;
}

/*
3

3 9
1 2 3
1 3 2
*/
