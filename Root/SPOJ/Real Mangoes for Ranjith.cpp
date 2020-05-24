#include "stdio.h"

int main()
{
    int t, n;
    long long k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        k = n - 2;
        k = k/2 + k%2;
        k = (k * k) % n;
        printf("%lld\n",k);
    }

    return 0;
}
