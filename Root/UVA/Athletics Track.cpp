#include "stdio.h"
#include "math.h"

int main()
{
    int test=0;
    double a,b,l,w,r,ratio,ang;
    while(scanf("%lf : %lf",&a,&b) == 2)
    {
        r = sqrt( (a*a + b*b) / 4 );
        ang = atan(b/a);
        ratio = 400 / (2*a + 4*r*ang);
        l = a * ratio;
        w = b * ratio;
        printf("Case %d: %.10lf %.10lf\n",++test,l,w);
    }

    return 0;
}
