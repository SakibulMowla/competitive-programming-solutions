#include <stdio.h>
#include <math.h>

typedef struct{
    double x,y;
} data;

int main()
{
    data arr[1010];
    int i,k,n;
    double dx,dy,gx,gy,d_d,d_g;

    while(scanf("%d",&n)==1)
    {
        scanf("%lf %lf %lf %lf",&gx,&gy,&dx,&dy);
        for(i=0;i<n;i++)
            scanf("%lf %lf",&arr[i].x,&arr[i].y);
        k=0;
        for(i=0;i<n;i++)
        {
            d_g=sqrt(pow(arr[i].x-gx,2) + pow(arr[i].y-gy,2));
            d_d=sqrt(pow(arr[i].x-dx,2) + pow(arr[i].y-dy,2))/2;
            if(d_g <= d_d)
            {
                k=1;
                printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",arr[i].x,arr[i].y);
                break;
            }
        }
        if(k==0)
            printf("The gopher cannot escape.\n");
    }


    return 0;
}
