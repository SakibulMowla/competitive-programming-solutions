#include "stdio.h"


int main()
{
    int n, i, sum, a, j;

    scanf("%d",&n);

    while(n--)
    {
        scanf("%d",&a);
        if(a&1)
        {
            printf("%d\n",a);
            continue;
        }

        for(i=24; i>=0; i--)
            if(a&(1<<i))
                break;

        sum = 0;
        j = 0;
        while(i>=0)
        {
            if(a&(1<<i))
                sum += (1<<j);
            j++;
            i--;
        }

        printf("%d\n",sum);
    }

    return 0;
}
