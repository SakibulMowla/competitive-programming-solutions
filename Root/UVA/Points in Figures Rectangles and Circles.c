#include <stdio.h>
#include <math.h>

typedef struct {
        char ch;
        double x1,y1,x2,y2;
} data;

int main()
{
    data arr[100];
    int i,j,k,l,n,m;
    double a,b;
    i=0;
    while(scanf(" %c",&arr[i].ch)==1)
    {
        if(arr[i].ch=='r')
            scanf("%lf %lf %lf %lf",&arr[i].x1,&arr[i].y1,&arr[i].x2,&arr[i].y2);
        else if(arr[i].ch=='c')
            scanf("%lf %lf %lf",&arr[i].x1,&arr[i].y1,&arr[i].x2);
        else if(arr[i].ch=='*')
            break;
        i++;
    }
    n=i;
    for(i=0;;i++)
    {
        scanf("%lf %lf",&a,&b);
        if(a==9999.9 && b==9999.9)
            break;
        k=0;
        for(j=0;j<n;j++)
        {
            if(arr[j].ch=='r')
            {
                if(a>arr[j].x1 && a<arr[j].x2 && b>arr[j].y2 && b<arr[j].y1)
                {
                    printf("Point %d is contained in figure %d\n",i+1,j+1);
                    k++;
                }
            }
            else if(arr[j].ch=='c')
            {
                if((pow(a-arr[j].x1,2)+pow(b-arr[j].y1,2)) < pow(arr[j].x2,2))
                {
                    printf("Point %d is contained in figure %d\n",i+1,j+1);
                    k++;
                }
            }
        }
        if(k==0)
            printf("Point %d is not contained in any figure\n",i+1);
    }
    return 0;
}
