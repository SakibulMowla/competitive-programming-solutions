#include <stdio.h>
#include <math.h>

int main()
{
    double ax,ay,bx,by,cx,cy,dx,dy,s,a,d1,d2,d3;

    int n,m,i,j,k,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy);
        dx=ax+(cx-bx);
        dy=ay+(cy-by);
        d1=sqrt(pow(ax-bx,2) + pow(ay-by,2));
        d2=sqrt(pow(ax-cx,2) + pow(ay-cy,2));
        d3=sqrt(pow(bx-cx,2) + pow(by-cy,2));
        s=(d1+d2+d3)/2;
        a=2*sqrt(s*(s-d1)*(s-d2)*(s-d3));
        printf("Case %d: %.0lf %.0lf %.0lf\n",i+1,dx,dy,a);
    }

    return 0;
}
