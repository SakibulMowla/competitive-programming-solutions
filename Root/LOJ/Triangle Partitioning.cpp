#include "stdio.h"
#include "string.h"
#include "math.h"

int main()
{
    int t=0, test, tmp;
    double a, b, c, d, e, s, angle, abc, ade, bdec, ratio, r, lo1, lo2, hi1, hi2;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%lf %lf %lf %lf",&a, &b, &c, &ratio);

        angle = acos( ( pow(a, 2) + pow(b, 2) - pow(c, 2) ) / ( 2 * a * b ) );
        s = (a + b + c) / 2;
        abc = sqrt (s*(s-a)*(s-b)*(s-c));

        lo1 = lo2 = 0;
        hi1 = a;
        hi2 = b;
        tmp = 50;

        while(tmp--)
        {
            d = (lo1 + hi1) / 2;
            e = (lo2 + hi2) / 2;

            ade = 0.5 * d * e * sin(angle);
            bdec = abc - ade;
            r = ade / bdec;

            if(r < ratio)
            {
                lo1 = d;
                lo2 = e;
            }
            else
            {
                hi1 = d;
                hi2 = e;
            }
        }

        printf("Case %d: %.10lf\n",++t,d);
    }

    return 0;
}
