#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

#define inf 1<<28
#define SD(n) scanf("%d",&n)
#define SC(n) scanf("%c",&n)
#define SLF(n) scanf("%lf",&n)
#define SS(n) scanf("%s",&n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 10010

int dp[SZ];

int main()
{
    int n,m,t,i,j;
    while(scanf("%d %d %d",&n,&m,&t) == 3)
    {
        memset(dp,0,sizeof(int)*(t+1));
        if(n > m) swap(n,m);
        dp[n] = dp[m] = 1;
        for(i=n; i<=t; i++)
        {
            if(dp[i])
            {
                if(i+n <= t) dp[i+n] = max(dp[i+n] , dp[i] + 1);
                if(i+m <= t) dp[i+m] = max(dp[i+m] , dp[i] + 1);
            }
        }
        if(dp[t]) printf("%d\n",dp[t]);
        else
        {
            j = 0;
            for(i=t-1; i>=0; i--)
            {
                if(dp[i] > 0)
                {
                    printf("%d %d\n",dp[i],t-i);
                    j = 1;
                    break;
                }
            }
            if(!j) printf("0 %d\n",t);
        }
    }

    return 0;
}
