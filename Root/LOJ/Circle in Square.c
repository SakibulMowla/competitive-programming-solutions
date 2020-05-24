#include <stdio.h>
#include <math.h>

int main()
{
    double r,a;
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&r);
        a=4*r*r-acos(-1)*r*r;
        printf("Case %d: %.2lf\n",i,a);
    }

    return 0;
}
