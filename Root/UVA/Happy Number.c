#include<stdio.h>

int main()
{
    int i,j,k,l,n,m,sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        k=m;sum=0;
        while(1)
        {
            for(j=k;j>0;j/=10)
            {
                l=j%10;
                sum+=l*l;
            }
            if(sum<10)
                break;
            k=sum;
            sum=0;
        }
        if(sum==1)
            printf("Case #%d: %d is a Happy number.\n",i+1,m);
        else
            printf("Case #%d: %d is an Unhappy number.\n",i+1,m);
    }
    return 0;
}
