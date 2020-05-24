#include "stdio.h"

int main()
{
    int n, m, i, j, sum;

    while(scanf("%d",&n) == 1)
    {
        sum = 0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            sum += j;
        }

        m = 0;

        for(i=1;i<=5;i++)
            if((sum+i) % (n+1) != 1) m++;

        printf("%d\n",m);
    }

    return 0;
}
