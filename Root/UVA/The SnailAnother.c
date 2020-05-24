#include <stdio.h>
#include <math.h>

int main()
{
    double h,u,d,f,sum,fatigue;
    int i;

    while(scanf("%lf %lf %lf %lf",&h,&u,&d,&f)==4)
    {
        if(h==0)break;
        sum=0;
        fatigue=f*u/100;
        for(i=1;;i++)
        {
            if(i>1 && u-fatigue >= 0)
                u-=fatigue;
            sum+=u;
            if(sum>h)
                {printf("success on day %d\n",i);break;}
            sum-=d;
            if(sum<0)
                {printf("failure on day %d\n",i);break;}
        }
    }
    return 0;
}
