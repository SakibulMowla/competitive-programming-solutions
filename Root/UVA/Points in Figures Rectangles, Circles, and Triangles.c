#include <stdio.h>
#include <math.h>

typedef struct
{
    char ch;
    double x1,y1,x2,y2,x3,y3;
} data;

int main()
{
    data arr[100];
    double x,y,a,b,c,A,A1,A2,A3;
    int i,j,k,l;

    i=0;
    while(scanf(" %c",&arr[i].ch)==1)
    {
        if(arr[i].ch=='*')
            break;
        else if(arr[i].ch=='r')
        {
            scanf("%lf %lf %lf %lf",&arr[i].x1,&arr[i].y1,&arr[i].x2,&arr[i].y2);
        }
        else if(arr[i].ch=='c')
        {
            scanf("%lf %lf %lf",&arr[i].x1,&arr[i].y1,&arr[i].x2);
        }
        else if(arr[i].ch=='t')
        {
            scanf("%lf %lf %lf %lf %lf %lf",&arr[i].x1,&arr[i].y1,&arr[i].x2,&arr[i].y2,&arr[i].x3,&arr[i].y3);
        }
        i++;
    }
    k=i;

    j=1;
    while(scanf("%lf %lf",&x,&y)==2)
    {
        if(x==9999.9 && y==9999.9)
            break;
        l=0;
        for(i=0; i<k; i++)
        {
            if(arr[i].ch=='r')
            {
                if(x>arr[i].x1 && x<arr[i].x2 && y>arr[i].y2 && y<arr[i].y1)
                {
                    printf("Point %d is contained in figure %d\n",j,i+1);
                    l++;
                }
            }
            else if(arr[i].ch=='c')
            {
                if(((x-arr[i].x1)*(x-arr[i].x1)) + ((y-arr[i].y1)*(y-arr[i].y1)) < arr[i].x2*arr[i].x2)
                {
                    printf("Point %d is contained in figure %d\n",j,i+1);
                    l++;
                }
            }
            else if(arr[i].ch=='t')
            {
                A=fabs(arr[i].x1*(arr[i].y2-arr[i].y3)-arr[i].y1*(arr[i].x2-arr[i].x3)+1*(arr[i].x2*arr[i].y3-arr[i].y2*arr[i].x3));
                A1=fabs(x*(arr[i].y2-arr[i].y3)-y*(arr[i].x2-arr[i].x3)+1*(arr[i].x2*arr[i].y3-arr[i].y2*arr[i].x3));
                A2=fabs(arr[i].x1*(y-arr[i].y3)-arr[i].y1*(x-arr[i].x3)+1*(x*arr[i].y3-y*arr[i].x3));
                A3=fabs(arr[i].x1*(arr[i].y2-y)-arr[i].y1*(arr[i].x2-x)+1*(arr[i].x2*y-arr[i].y2*x));

                if(fabs(A-A1-A2-A3) <= 0.000001)
                {
                    printf("Point %d is contained in figure %d\n",j,i+1);
                    l++;
                }
            }
        }
        if(l==0)
            printf("Point %d is not contained in any figure\n",j);

        j++;
    }

    return 0;
}
