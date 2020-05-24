#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,r;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3)
    {
        if(a<=0 || b<=0 || c<=0 || (a+b)<=c || (b+c)<=a || (c+a)<=b)
            {printf("-1.000\n");continue;}
        r=(1.0/3.0)*(sqrt(2*((pow(a,2)*pow(b,2))+(pow(b,2)*pow(c,2))+(pow(c,2)*pow(a,2)))-(pow(a,4)+pow(b,4)+pow(c,4))));
        printf("%.3lf\n",r);
    }
    return 0;
}
