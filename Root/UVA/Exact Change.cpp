#include <stdio.h>
#include <string.h>
#include <math.h>

#define inf 100000
#define ll long long

ll coin[100+10];
ll dp[20010];
int main()
{
    ll i,j,test,price,bills,v,coin_num,money,res;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&price);
        scanf("%lld",&bills);
        for(j=0; j<bills; j++)
            scanf("%lld",&coin[j]);
        dp[0]=0;
        for(j=1; j<20010; j++)
            dp[j]=inf;
        dp[0]=0;
        res=inf;
        for(j=0; j<bills; j++)
        {
            for(v=10000; v>=0; v--)
            {
                printf("v=%lld\n",v);
                if(dp[v] != inf  &&  v+coin[j]<=10000  &&  dp[v+coin[j]] > dp[v]+1)
                {
                    printf("v=%lld j=%lld\n",v,j);
                    dp[v+coin[j]]=dp[v] + 1;

                    if(v+coin[j] < res  &&   v+coin[j] >= price  &&  dp[v+coin[j]] != inf)
                        printf("yes\n"),res=v + coin[j];
                }
            }
        }

        printf("%lld %lld\n",res,dp[res]);
    }

    return 0;
}
