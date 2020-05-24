#include "stdio.h"
#include "math.h"

int main()
{
    int test,n,b,i,j,k,sum,mul,cho;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&b);
        sum = 0;
        for(i=0;i<b;i++)
        {
            scanf("%d",&k);
            mul = 1;
            for(j=0;j<k;j++)
            {
                scanf("%d",&cho);
                mul = (mul * cho) % n;
            }
            sum = (sum + mul) % n;
        }
        printf("%d\n",sum);
    }

    return 0;
}
