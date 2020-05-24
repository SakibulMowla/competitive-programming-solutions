#include "stdio.h"
#include "string.h"
#include "math.h"

#define SZ 10010
#define limit 1000010

int arr[limit];

void sieve()
{
    int i,j;
    arr[0] = arr[1] = 1;
    for(i=4;i<limit;i+=2) arr[i] = 1;
    for(i=3;i<=sqrt(limit);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<limit;j+=i+i)
                arr[j] = 1;
}

int dp[SZ];

int main()
{
    sieve();
    int t,test,n,q,num,identi,i,j,start,end,x,cnt;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            if(arr[num] == 0)
                dp[i] = dp[i-1] + 1;
            else dp[i] = dp[i-1];
        }
        printf("Case %d:\n",++t);
        while(q--)
        {
            scanf("%d",&identi);
            if(identi == 0)
            {
                scanf("%d %d %d",&start,&end,&x);
                if(arr[x] == 0)
                {
                    for(i=start;i<=end;i++)
                        dp[i] = dp[i-1] + 1;
                    x = (end - start) + 1;
                    for(i=end+1;i<=n;i++)
                        dp[i] = dp[i] + x;
                }
                else
                {
                    cnt = 0;
                    for(i=start;i<=end;i++)
                        if(dp[i] > dp[i-1]) cnt++;

                    for(i=start;i<=end;i++)
                        dp[i] = dp[i-1];
                    for(i=end+1;i<=n;i++)
                        dp[i] = dp[i] - cnt;
                }
            }
            else if(identi == 1)
            {
                scanf("%d %d",&start,&end);
                printf("%d\n",dp[end] - dp[start-1]);
            }
        }
    }

    return 0;
}
