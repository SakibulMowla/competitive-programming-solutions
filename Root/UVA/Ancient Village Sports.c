#include <stdio.h>
#include <math.h>

int main(void)
{
    double a,co,ci;
    int i,n;
    i=1;
    while(scanf("%d %lf",&n,&a)==2)
    {
        if(n<3)
            break;
        co=(acos(-1)*2*a)/(n*sin(2*acos(-1)/n))-a;
        ci=a-(acos(-1)*a)/(n*tan(acos(-1)/n));
        printf("Case %d: %.5lf %.5lf\n",i,co,ci);
        i++;
    }
    return 0;
}
