#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,c,r,k;

    while(scanf("%lf %lf %lf",&a,&b,&c) == 3)
    {
        k=(a+b+c)/2;
        if(k==0)
        {
            printf("The radius of the round table is: 0.000\n",r);
            continue;;
        }
        r=sqrt(k*(k-a)*(k-b)*(k-c))/k;
        printf("The radius of the round table is: %.3lf\n",r);
    }

    return 0;
}
