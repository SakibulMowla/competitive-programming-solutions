#include<stdio.h>

int main(void)
{
    long long int i,n,sum,c;
    while(scanf("%lld",&n)==1)
    {
        sum=(1%n);
        c=1;
        while(sum!=0)
        {
            sum=((sum*10)+1)%n;
            c++;
        }

        printf("%lld\n",c);
    }

    return 0;
}
