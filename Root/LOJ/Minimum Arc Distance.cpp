#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

#define pi 2*acos(0)

int main()
{
    double ox,oy,ax,ay,bx,by,m1,m2,theta,radius,arc;
    int t,test;
    t = 0;
    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&ox,&oy,&ax,&ay,&bx,&by);
        m1 = (ox-ax == 0 ? (oy-ay) :(oy-ay) / (ox-ax));
        m2 = (ox-bx == 0 ? (oy-by) :(oy-by) / (ox-bx));
        theta = atan( ( (m1-m2) / (1 + m1*m2) ) /** ( pi / 180)*/);
        if(theta > 180) theta = 360 - theta;
        radius = sqrt( pow(ox-ax , 2) + pow(oy-ay , 2) );
        arc = radius * theta;
        if(arc < 0) arc *= -1;
//        printf("m1=%lf  m2=%lf\n",m1,m2);
        printf("Case %d: %.8lf\n",++t,arc);
    }

    return 0;
}
