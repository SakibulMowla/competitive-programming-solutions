#include "stdio.h"
#include "math.h"

int main()
{
    int a1,a2,b1,b2,c1,c2,d;
    double x,y;
    while(scanf("%d %d %d %d %d %d",&a1,&b1,&c1,&a2,&b2,&c2) == 6)
    {
        if(a1==0 && a2==0 && b1==0 && b2==0 && c1== 0 && c2==0)break;
        d = (a2*b1) - (a1*b2);
        if(d == 0)
        {
            printf("No fixed point exists.\n");
            continue;
        }
        x = (double)( (c2*b1) - (c1*b2) ) / d;
        y = ( c1 - (a1*x) ) / b1;
        printf("The fixed point is at %.2lf %.2lf.\n",x,y);
    }

    return 0;
}
