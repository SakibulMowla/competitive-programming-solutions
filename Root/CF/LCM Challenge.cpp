#include "stdio.h"

int main()
{
    long long n;
    while(scanf("%I64d",&n) == 1)
    {
        if(n <= 2) ;
        else if(n % 2 == 1) n = n*(n-1)*(n-2);
        else if(n % 3 == 0) n = (n-1)*(n-2)*(n-3);
        else n = n*(n-1)*(n-3);
        printf("%I64d\n",n);
    }
    return 0;
}
