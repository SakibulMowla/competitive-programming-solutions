#include <stdio.h>
#include <math.h>

#define max 1010

int main()
{
    double cost[max],sum,avg,exc;
    int n,i;
    while(scanf("%d",&n)==1 &&n)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&cost[i]);
            sum+=cost[i];
        }
        avg=sum/n;
        exc=0;
        for(i=0;i<n;i++)
        {
            if(cost[i]<avg)
                exc+=avg-cost[i];
        }
        printf("$%lf\n",exc);
    }
    return 0;
}
