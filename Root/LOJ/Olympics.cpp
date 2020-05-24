#include "stdio.h"
#include "math.h"

int main()
{
    int t=0, test;
    double a, b, r, l, w, ratio, angle;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%lf : %lf",&a,&b);

        r = sqrt( ( (a*a) + (b*b) ) / 4 );
        angle = atan(b/a);
        ratio = 400 / ( 4*r*angle + 2*a );
        l = ratio * a;
        w = ratio * b;

        printf("Case %d: %.10lf %.10lf\n",++t,l,w);
    }

    return 0;
}
