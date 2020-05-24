#include<stdio.h>

typedef struct
{
    double x1,y1,x4,y4;
} data;

int main()
{
    data arr[100];
    int i,j,k,n;
    double a,b,c,d;
    char ch;
    i=0;
    while(scanf(" %c",&ch)==1)
    {
        if(ch=='*')
            break;
        scanf("%lf %lf %lf %lf",&arr[i].x1,&arr[i].y1,&arr[i].x4,&arr[i].y4);
        ++i;
    }

    n=i;
    for(i=0;; i++)
    {
        scanf("%lf %lf",&a,&b);
        if(a==9999.9 && b==9999.9)
            break;
        k=0;
        for(j=0; j<n; j++)
        {
            if(a>arr[j].x1 && a<arr[j].x4 && b>arr[j].y4 && b<arr[j].y1)
            {
                printf("Point %d is contained in figure %d\n",i+1,j+1);
                k++;
            }
        }
        if(k==0)
            printf("Point %d is not contained in any figure\n",i+1);
    }
    return 0;
}
