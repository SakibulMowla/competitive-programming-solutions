#include <stdio.h>
#include <math.h>

int main()
{
    double n,p,r;
    while(scanf("%lf %lf",&p,&n)==2)
    {
        r=pow(n,(1/p));
        printf("%.0lf\n",r);
    }

    return 0;
}
