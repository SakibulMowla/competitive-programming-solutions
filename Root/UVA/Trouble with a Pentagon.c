#include <stdio.h>
#include <math.h>

int main()
{
    double p,s;
    while(scanf("%lf",&p)==1)
    {
        s=p*sin(acos(-1)*108/180)/sin(acos(-1)*63/180);
        printf("%.10lf\n",s);
    }

    return 0;
}
