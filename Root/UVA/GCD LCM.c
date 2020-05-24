#include <stdio.h>

int main()
{
    long long int n,i,a,b;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&a,&b);
        if(b%a==0)
            printf("%lld %lld\n",a,b);
        else
            printf("-1\n");
    }

    return 0;
}
