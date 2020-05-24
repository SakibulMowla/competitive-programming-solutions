// taking any two points from the diagonal to make a line ,so number of lines: nC2 - n
// here given the value of x
// nC2 - n = x
// n(n-1)/2 - n =x
// n = 3 + sqrt(9+8x)/2

#include "stdio.h"
#include "math.h"

int main()
{
    long long test=0,n,x;
    while(scanf("%lld",&x) == 1 && x)
    {
        n = ceil((3 + sqrt(9 + 8 * x)) / 2);
        printf("Case %lld: %lld\n",++test,n);
    }

    return 0;
}
