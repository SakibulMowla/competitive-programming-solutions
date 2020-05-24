#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



int main()
{
    int i,j,k;
    double dif,mean,arr[20];
    while(scanf("%lf",&arr[0]) == 1)
    {
        dif = arr[0];
        for(i=1;i<12;i++)
        {
            scanf("%lf",&arr[i]);
            dif += arr[i];
        }
        mean = dif / 12;
        printf("$%.2lf\n",mean);
    }

    return 0;
}
