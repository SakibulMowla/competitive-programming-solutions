#include <stdio.h>
#include <string.h>
#include <math.h>

int arr[100];

int GCD(int a,int b)
{
    if(b == 0)
        return a;
    return GCD(b,a%b);
}

int main()
{
    int test,t,i,j,total,count,res;
    double pi;
    while(scanf("%d",&test) == 1 && test)
    {
        for(i=0;i<test;i++)
            scanf("%d",&arr[i]);
        count=0;
        for(i=0;i<test-1;i++)
        {
            for(j=i+1;j<test;j++)
            {
                res=GCD(arr[i],arr[j]);
                if(res==1)
                    count++;
            }
        }
        if(count == 0)
            printf("No estimate for this data set.\n");
        else
        {
            total=test*(test-1)/2;
            pi=sqrt(6.0*total/count);
            printf("%.6lf\n",pi);
        }

    }

    return 0;
}
