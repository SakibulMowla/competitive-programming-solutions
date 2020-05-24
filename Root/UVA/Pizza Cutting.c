#include<stdio.h>

int main()
{
    long long int n,i,sum;

    while((scanf("%lld",&n))==1)
    {
        if(n<0)
            break;
        sum=1;
        for(i=1;i<=n;i++)
        {
            sum+=i;
        }
        printf("%lld\n",sum);
    }

    return 0;
}
