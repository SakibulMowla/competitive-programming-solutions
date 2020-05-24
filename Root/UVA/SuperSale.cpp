#include <stdio.h>
#include <string.h>

#define max(a,b) a>b?a:b
#define SZ 1010

int cost[SZ],weight[SZ];
int dp[SZ][32];
bool color[SZ][32];
int items,cap;

int knapsack(int i,int w)
{
    if(i==items+1)
        return 0;
    if(color[i][w] == 1)
        return dp[i][w];
    int profit1,profit2;
    if(w+weight[i] <= cap)
        profit1 = cost[i] + knapsack(i+1,w+weight[i]);
    else
        profit1 = 0;
    profit2 = knapsack(i+1,w);

    dp[i][w] = max(profit1,profit2);
    color[i][w] = 1;

    return dp[i][w];
}

int main()
{
    int i,t,test,g,profit;
    scanf("%d",&test);
    for(t=0;t<test;t++)
    {
        scanf("%d",&items);
        for(i=1;i<=items;i++)
        {
            scanf("%d %d",&cost[i],&weight[i]);
        }
        scanf("%d",&g);
        profit=0;
        for(i=0;i<g;i++)
        {
            scanf("%d",&cap);
            memset(color,0,sizeof(color));
            profit+=knapsack(1,0);
        }
        printf("%d\n",profit);
    }

    return 0;
}
