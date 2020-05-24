#include <stdio.h>
#include <math.h>

int main()
{
    int arr[600],t,d,n,m,m1,m2,i,j,k,temp;
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        scanf("%d",&t);
        for(i=0;i<t;i++)
            scanf("%d",&arr[i]);

        for(i=0;i<t-1;i++)
            for(j=i+1;j<t;j++)
                if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
        if(t%2==1)
            m=arr[t/2];
        else if(t%2==0)
        {
            m1=arr[t/2];
            m2=arr[(t/2)-1];
            m=(m1+m2)/2;
        }

        d=0;
        for(i=0;i<t;i++)
        {
            d+=abs(arr[i]-m);
        }
        printf("%d\n",d);
    }
    return 0;
}
