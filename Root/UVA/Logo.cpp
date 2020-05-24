#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define pi 2*acos(0.0)

int main()
{
    int test,cmnd,i,j,unit;
    double x,y,angle;
    char arr[10];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&cmnd);
        x = y = angle = 0;
        while(cmnd--)
        {
            scanf("%s %d",arr,&unit);
            if(strcmp(arr,"fd") == 0)
            {
                x += unit * cos(angle * pi /180);
                y += unit * sin(angle * pi /180);
            }
            else if(strcmp(arr,"bk") == 0)
            {
                x -= unit * cos(angle * pi /180);
                y -= unit * sin(angle * pi /180);
            }
            else if(strcmp(arr,"lt") == 0)
            {
                angle += unit;
                angle = fmod(angle,360);
            }
            else if(strcmp(arr,"rt") == 0)
            {
                angle -= unit;
                angle = fmod(angle,360);
            }
        }
        printf("%.0lf\n",sqrt(x*x + y*y));
    }

    return 0;
}
