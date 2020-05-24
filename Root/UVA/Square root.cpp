#include "stdio.h"
#include "math.h"

int main()
{
    long long t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%.0lf\n",sqrt(n));
        if(t) printf("\n");
    }

    return 0;
}
