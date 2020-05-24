#include <stdio.h>
#include <math.h>

int main()
{
    double x,dx,x1,x2,x3,y,y1,y2,y3,dy,d,r,i,j,k;
    char s1,s2,s3;

    while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
    {
        d=(x1-x2)*(y1-y3)-(x1-x3)*(y1-y2);
        dx=((pow(x1,2)-pow(x2,2)+pow(y1,2)-pow(y2,2))*(y1-y3)/2)-((pow(x1,2)-pow(x3,2)+pow(y1,2)-pow(y3,2))*(y1-y2)/2);
        dy=((pow(x1,2)-pow(x3,2)+pow(y1,2)-pow(y3,2))*(x1-x2)/2)-((pow(x1,2)-pow(x2,2)+pow(y1,2)-pow(y2,2))*(x1-x3)/2);
        x=dx/d;
        y=dy/d;
        r=sqrt(pow(x-x1,2)+pow(y-y1,2));
        i=2*x;
        j=2*y;
        k=pow(x,2)+pow(y,2)-pow(r,2);

        if(x>0) s1='-';
        else s1='+';
        if(y>0) s2='-';
        else s2='+';
        printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",s1,fabs(x),s2,fabs(y),fabs(r));

        if(i>0) s1='-';
        else s1='+';
        if(j>0) s2='-';
        else s2='+';
        if(k>=0) s3='+';
        else s3='-';
        printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n",s1,fabs(i),s2,fabs(j),s3,fabs(k));

        printf("\n");
    }
    return 0;
}
