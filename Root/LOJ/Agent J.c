#include <stdio.h>
#include <math.h>

int main()
{
    int i,n;
    double r1,r2,r3,a,b,c,total_area,s,at,ar1,ar2,ar3,ra;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        a=r2+r3;
        b=r1+r3;
        c=r1+r2;
        s=(a+b+c)/2;
        at=sqrt(s*(s-a)*(s-b)*(s-c));
        ar1=.5*r1*r1*acos((c*c + b*b - a*a)/(2*b*c));
        ar2=.5*r2*r2*acos((c*c + a*a - b*b)/(2*a*c));
        ar3=.5*r3*r3*acos((b*b + a*a - c*c)/(2*a*b));
        ra=at-ar1-ar2-ar3;
        printf("Case %d: %.10lf\n",i+1,ra);
    }

    return 0;
}
