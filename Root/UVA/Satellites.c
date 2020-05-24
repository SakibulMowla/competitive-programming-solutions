#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    double a,s,r,arc_dis,cho_dis;
    r=6440;
    char arr[10];
    while(scanf("%lf %lf %s",&s,&a,arr)==3)
    {
        if(strcmp(arr,"min")==0)
            a=a/60;
        if(a>359)
        {
            arc_dis=0;
        }
        else
        {
            if(a>180)
                a=(360-a);
            arc_dis=a*acos(-1)/180*(s+r);
        }
        a=(int)a%360+(a-(int)a);
        if(a>180)
            a=(360-a);
        cho_dis=2*(s+r)*sin(a*acos(-1)/180/2);
        printf("%lf %lf\n",arc_dis,cho_dis);
    }

    return 0;
}
