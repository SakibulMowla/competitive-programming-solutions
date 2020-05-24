#include<stdio.h>
#include<math.h>

int main()
{
    int l,w,h,o;
    double r;
    while(scanf("%d %d %d %d",&l,&w,&h,&o)==4)
    {
        if((l*tan(o*acos(-1)/180)>h))
            r=.5*h*h*w/tan(o*acos(-1)/180);
        else
            r=l*w*(2*h-l*tan(o*acos(-1)/180))/2;
        printf("%.3lf mL\n",r);
    }
    return 0;
}

