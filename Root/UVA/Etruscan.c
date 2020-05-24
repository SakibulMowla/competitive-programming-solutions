#include<stdio.h>
#include<math.h>

int main(void)
{
    long long int n,i,c,m;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&m);
        c=(sqrt(1+8*m)-1)/2;
        printf("%lld\n",c);
    }

    return 0;
}
