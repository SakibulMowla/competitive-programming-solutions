#include "stdio.h"
#include "math.h"

int main()
{
    int t=0,n;
    double d;
    while(scanf("%d",&n) == 1 && n>0)
    {
        d = ceil(log(n)/log(2));
        printf("Case %d: %.0lf\n",++t,d);
    }

    return 0;
}
