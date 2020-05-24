#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, sum, best, sumb;
    int arr[12];

    for(i=0; i<10; i++)   scanf("%d",&arr[i]);

    sumb = 1<<28;
    best = 1<<28;
    sum = 0;

    for(i=0; i<10; i++)
    {
        sum += arr[i];
        if(abs(100-sum) < best)
        {
            best = abs(100-sum);
            sumb = sum;
        }

        if(abs(100-sum) == best)
        {
            if(sum > sumb)
                sumb = sum;
        }
    }

    printf("%d\n",sumb);

    return 0;
}
