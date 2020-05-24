#include <stdio.h>

int main()
{
    long long int test , n;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        n = n & (n-1);
        printf("%lld\n",n);
    }
}
