#include "stdio.h"
#include "math.h"

int main()
{
    long long n,res;
    while(scanf("%lld",&n) == 1)
    {
        res = (n-1) + log2(n-1);
        printf("%lld\n",res);
    }
    return 0;
}
