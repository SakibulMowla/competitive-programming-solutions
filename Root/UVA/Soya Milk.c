#include<stdio.h>
#include<math.h>

int main()
{
    int l,w,h,o;
    double r;
    while(scan("%d %d %d %d",&l,&w,&h,&o)==4);
    {
        r=l*w*(2*h-l*tan(o*acos(-1)/180))/2;
        printf("%.3lf mL\n",r);
    }
    return 0;
}
