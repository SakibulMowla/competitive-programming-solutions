#include <stdio.h>
#include <math.h>

int main()
{
    double a,ao,ad,as;
    while(scanf("%lf",&a)==1)
    {
        ao=(a*a)*(4-sqrt(3)-(2*acos(-1)/3));
        ad=(a*a)*(4-acos(-1))-(2*ao);
        as=(a*a)-ao-ad;
        printf("%.3lf %.3lf %.3lf\n",as,ad,ao);
    }
    return 0;
}
