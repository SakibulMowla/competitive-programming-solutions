#include "stdio.h"
#include "math.h"

const double pi = 2.0 * acos(0.0);

int main()
{
    double a,b,l,d;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf",&d,&l);
        a = l / 2;
        b = sqrt( (l/2 * l/2) - (d/2 * d/2) );
        d = pi * a * b;
        printf("%.3lf\n",d);
    }

    return 0;
}
