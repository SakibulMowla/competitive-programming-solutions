#include <stdio.h>
#include <string.h>

int main()
{
    int coins[110],nways[10010];
    int n,money,i,j,k,t,test,way;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d %d",&n,&way);
        for(i=0;i<n;i++)
        {
            scanf("%d",&money);
            coins[i]=money;
        }
        memset(nways,0,sizeof(nways));
        nways[0]=1;
        for(i=0;i<n;i++)
        {
            for(j=coins[i],k=0;j<=way;j++,k++)
            {
                nways[j] = ( nways[j] + nways[k] )% 100000007;
            }
        }
        memset(coins,0,sizeof(coins));
        printf("Case %d: %d\n",t,nways[way]);
    }

    return 0;
}
