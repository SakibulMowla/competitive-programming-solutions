#include "stdio.h"
#include "string.h"

#define SD(n) scanf("%d",&n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)

int dp[100010] , used[100010], A[110] , C[110];

int main()
{
    int t=0,test,n,m,i,j,cnt;
    SD(test);
    while(test--)
    {
        SD(n) , SD(m);
        FOR(i,n) SD(A[i]);
        FOR(i,n) SD(C[i]);
        FORI(i,0,m)dp[i] = 0;
        dp[0] = 1;
        cnt = 0;
        FOR(i,n)
        {
            memset(used,0,sizeof(int) * (m+1));
            for(j=A[i];j<=m;j++)
            {
                if(!dp[j] && dp[j-A[i]] && used[j-A[i]] < C[i])
                {
                    cnt++;
                    dp[j] = 1;
                    used[j] = used[j-A[i]] + 1;
                }
            }
        }
        printf("Case %d: %d\n",++t,cnt);
    }

    return 0;
}
