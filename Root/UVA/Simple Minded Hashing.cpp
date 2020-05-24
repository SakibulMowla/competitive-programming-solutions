#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SD(n) scanf("%d",&n)
#define SZ 30


int len,tot,dp[SZ][SZ][401];

int bctk(int n,int last,int sum)
{
    if(sum > tot || sum > 400 ) return 0;
    if(n==len)
    {
        if(sum==tot)return 1;
        return 0;
    }
    if(dp[n][last][sum] != -1) return dp[n][last][sum];
    int i,way=0;
    for(i=last+1; i<=26; i++) way += bctk(n+1,i,sum+i);
    return dp[n][last][sum] = way;
}

int main()
{
    int t=0,i,j,k;
    while(scanf("%d %d",&len,&tot) == 2 && (len+tot))
    {
        if(len>26 || tot > 351) {printf("Case %d: 0\n",++t);continue;}
        FORI(i,0,29)FORI(j,0,29)FORI(k,0,tot)dp[i][j][k] = -1;
        printf("Case %d: %d\n",++t,bctk(0,0,0));
    }

    return 0;
}
