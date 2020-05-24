#include <stdio.h>
#include <math.h>

int deg[365];

int main()
{
    int i,hour,min,anglh,anglm,dif;
    min = 0;
    for(hour=0;hour<60;hour++)
    {
        for(i=0;i<12;i++)
        {
            anglh = (hour * 6) % 360;
            anglm = (min * 6) % 360;
            dif = (anglm - anglh + 360) % 360;
            if(dif > 180) dif = 360 - dif;
            deg[dif] = 1;
            min++;
        }
    }
    while(scanf("%d",&i) == 1)
    {
        deg[i] ? printf("Y\n") : printf("N\n");
    }

    return 0;
}
