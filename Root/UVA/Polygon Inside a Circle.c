#include<stdio.h>
#include<math.h>
int main()
{
    double r,n,d,a;
    while(scanf("%lf %lf",&r,&n)==2)
    {
        a=sin(2*acos(-1)/n);
        d=r*r*n*a/2;
        printf("%.3lf\n",d);
    }
    return 0;
}
