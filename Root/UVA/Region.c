#include <stdio.h>
#include <math.h>

int main()
{
    double r1,r2,r3,ta,b,c,s,a,a1,a2,a3,t;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        if(r1==0 || r2==0 ||r3==0)
        {
            printf("0.000000\n");
            continue;
        }
        a=r3+r2;
        b=r1+r3;
        c=r2+r1;
        s=(a+b+c)/2;
        ta=sqrt(s*(s-a)*(s-b)*(s-c));
        a1=.5*r1*r1*acos((b*b + c*c - a*a)/(2*b*c));
        a2=.5*r2*r2*acos((a*a + c*c - b*b)/(2*a*c));
        a3=.5*r3*r3*acos((a*a + b*b - c*c)/(2*a*b));
        t=ta-(a1+a2+a3);
        printf("%.6lf\n",t);
    }

    return 0;
}
