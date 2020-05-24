#include<stdio.h>

double angle(double x,double y);
int main()
{
    double a,b,n;
    while((scanf("%lf:%lf",&a,&b))==2)
    {
        if(a==0 && b==0)
            break;
        n=angle(a,b);
        printf("%.3lf\n",n);
    }
    return 0;
}


double angle(double x,double y)
{
    double c,d,e,f;
    c=x*5;
    d=(5*y)/60;
    e=c+d-y;
    if(e<0)
        e=e*(-1);
    f=e*6;
    if(f<=180)
        return f;
    else
        return (360-f);
}
