#include<stdio.h>

int main()
{
    int arr[1000],i,n,sum,a,c,j=1;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        sum=0;c=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        a=sum/n;
        for(i=0;i<n;i++)
        {
            if(arr[i]>a)
                c+=(arr[i]-a);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",j,c);
        j++;
    }
    return 0;
}
