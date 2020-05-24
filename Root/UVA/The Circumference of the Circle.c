#include<stdio.h>
#include<math.h>

int main()
{
    double x,y,x1,y1,x2,y2,x3,y3,dx,dy,d,r,c;
    while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
    {
        d=(x1-x2)*(y1-y3)-(x1-x3)*(y1-y2);
        dx=((pow(x1,2)-pow(x2,2)+pow(y1,2)-pow(y2,2))*(y1-y3)/2)-((pow(x1,2)-pow(x3,2)+pow(y1,2)-pow(y3,2))*(y1-y2)/2);
        dy=((pow(x1,2)-pow(x3,2)+pow(y1,2)-pow(y3,2))*(x1-x2)/2)-((pow(x1,2)-pow(x2,2)+pow(y1,2)-pow(y2,2))*(x1-x3)/2);
        x=dx/d;
        y=dy/d;
        r=sqrt(pow(x-x1,2)+pow(y-y1,2));
        c=2*3.141592653589793*r;
        printf("%.2lf\n",c);
    }

    return 0;
}
