#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n,b,h,w,price,i,j,k,l,beds,min_cost,cost;
    while(scanf("%d %d %d %d",&n,&b,&h,&w) == 4)
    {
        min_cost=-1;
        for(i=0;i<h;i++)
        {
            scanf("%d",&price);
            for(j=0;j<w;j++)
            {
                scanf("%d",&beds);
                if(beds>=n)
                {
                    cost=n*price;
                    if((cost <= b && min_cost==-1) || (cost <= b && cost<min_cost))
                        min_cost=cost;
                }
            }
        }
        if(min_cost==-1)
            printf("stay home\n");
        else
            printf("%d\n",min_cost);
    }

    return 0;
}
