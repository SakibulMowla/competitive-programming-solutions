#include "stdio.h"
#define SZ 65

typedef unsigned long long ll;

ll dp[SZ][SZ];


ll solve(int n, int back)
{
    if(n<=1) return 1;

    ll &ret = dp[n][back];
    if(ret != -1) return ret;

    int i;
    ret = 1LL;

    for(i=1;i<=back;i++)
         ret += solve(n-i, back);

    return ret;
}

int main()
{
    int n, m, i, j, test = 0;

    while(~scanf("%d %d",&n,&m))
    {
        if(n > 60) break;

        for(i=0;i<=n;i++)
            for(j=0;j<=m;j++)
                dp[i][j] = -1;

        printf("Case %d: %llu\n",++test,solve(n, m));
    }

    return 0;
}
