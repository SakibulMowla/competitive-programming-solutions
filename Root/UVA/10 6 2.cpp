#include <stdio.h>
#include <math.h>

#define pi acos(-1)

int main()
{
    int len,t;
    double width , radius , green , red;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&len);
        width = ((double)len * 6) / 10;
        radius = (double)len / 5;
        red = pi * radius * radius;
        green = (double)len * width - red;
        printf("%.2lf %.2lf\n",red,green);
    }

    return 0;
}
