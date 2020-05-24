#include <stdio.h>
#include <string.h>

#define max(a,b) a>b?a:b

int dp[30][300];
bool color[30][300];
int cost[30];
int n,cap;

int knapsack(int i,int w)
{
    if(i == n+1)
        return 0;
    if(color[i][w] == 1)
        return dp[i][w];
    int profit1,profit2;
    if(w+cost[i] <= cap)
        profit1=cost[i]+knapsack(i+1,w+cost[i]);
    else
        profit1=0;
    profit2=knapsack(i+1,w);
    dp[i][w]=max(profit1,profit2);
    color[i][w]=1;

    return dp[i][w];
}


int main()
{
    int test,len,i,car1,car2,sum;
    char prech,ch,z,arr[200];
    scanf("%d%c",&test,&z);
    while(test--)
    {
        n=0;
        memset(color,0,sizeof(color));
        prech=' ';
        gets(arr);
        len=strlen(arr);
        for(i=0; i<len; i++)
        {
            ch=arr[i];
            if(prech==' ' && ch>='0' && ch<='9')
            {
                ++n;
                cost[n]=ch-'0';
            }
            else if(ch>='0' && ch<='9' && prech>='0' && prech<='9')
            {
                cost[n]=(cost[n]*10)+(ch-'0');
            }
            prech=ch;
        }
        sum=0;
        for(i=1; i<=n; i++)
            sum+=cost[i];
        if(sum%2==1)
        {
            printf("NO\n");
            continue;
        }
        cap=sum/2;
        car1=sum-(sum/2);
        car2=knapsack(1,0);
        if(car1-car2 == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
