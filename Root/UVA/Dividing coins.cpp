#include <stdio.h>
#include <string.h>

#define max(a,b) a>b?a:b
#define absolute(a,b) a>b?a-b:b-a

int dp[110][50005];
bool color[110][50005];
int cost[110];
int coins,cap;

int knapsack(int i,int w)
{
    if(i == coins+1)
        return 0;
    if(color[i][w] != 0)
        return dp[i][w];
    int profit1,profit2;
    if(w+cost[i] <= cap)
        profit1=cost[i] + knapsack(i+1,w+cost[i]);
    else
        profit1=0;
    profit2=knapsack(i+1,w);

    color[i][w]=1;
    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}

int main()
{
    int test,sum,man1,man2,i,res;
    scanf("%d",&test);
    while(test--)
    {
        memset(color,0,sizeof(color));
        scanf("%d",&coins);
        sum=0;
        for(i=1;i<=coins;i++)
        {
            scanf("%d",&cost[i]);
            sum+=cost[i];
        }
        cap=sum/2;
        man1=sum-(sum/2);
        man2=knapsack(1,0);
        res=absolute(man1,man2) ;
        res+=sum-(man1+man2);
        printf("%d\n",res);
    }

    return 0;
}
