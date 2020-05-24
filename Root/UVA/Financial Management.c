#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double sum,mean,input;
    long coma;
    int n,i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        sum=0;
        for(j=1; j<=12; j++)
        {
            scanf("%lf",&input);
            sum+=input;
        }
        mean=sum/12.0;
        printf("%d $",i);
        if(mean>999.0)
        {
            coma=mean/1000.0;
            printf("%ld,",coma);
        }
        printf("%.2lf\n",fmod(mean,1000.0));
    }
    return 0;
}
