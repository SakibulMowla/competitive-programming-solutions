#include<stdio.h>

int main()
{
    long long int n,i,j,arr[1000];

    while((scanf("%lld",&n))==1)
    {
        if(n<0)
            break;
        if(n==0)
            {printf("0\n");continue;}

        for(i=0;n>0;i++)
        {
            arr[i]=n%3;
            n/=3;
        }
        for(j=i-1;j>=0;j--)
        {
            printf("%lld",arr[j]);
        }
        printf("\n");
    }

    return 0;
}
