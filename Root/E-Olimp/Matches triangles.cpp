#include <stdio.h>
#include <math.h>

int main()
{
    long long n;
    while(scanf("%lld",&n) == 1)
    {
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        if(n==1)
        {
            printf("3\n");
            continue;
        }
        n = (n * 2) + 1;
        printf("%lld\n",n);
    }

    return 0;
}
