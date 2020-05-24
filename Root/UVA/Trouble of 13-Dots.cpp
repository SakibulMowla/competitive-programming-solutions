#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) a>b?a:b
#define SZ 110

int cost[SZ];
int favor[SZ];
bool color[SZ][10010];
int dp[SZ][10010];
int pm,test;

int knap(int i,int c)
{
    if(i==test+1)
        return 0;
    if(color[SZ][SZ] != 0)
        return dp[i][c];
    int profit1,profit2;
    if(c+cost[i] <= pm)
        profit1=favor[i] + knap(i+1 , c+cost[i]);
    else
        profit1 = 0;
    profit2 = knap(i+1 , c);
    dp[i][c] = max(profit1 , profit2);
    color[i][c] = 1;

    return dp[i][c];
}

int main()
{
    int i,ans;
    while(scanf("%d %d",&pm,&test) == 2)
    {
        if(pm > 2000)
            pm += 200;
        memset(color,0,sizeof(color));
        for(i=1;i<=test;i++)
        {
            scanf("%d %d",&cost[i],&favor[i]);
        }
        ans=knap(1,0);
        printf("%d\n",ans);
    }

    return 0;
}
