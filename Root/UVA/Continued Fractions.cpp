#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int r,d,n;
    while(scanf("%d %d",&n,&d) == 2)
    {
        printf("[%d;",n/d);
        while(1)
        {
            r = n % d;
            n = d;
            d = r;
            printf("%d",n/d);
            if(n % d == 0)
                break;
            printf(",");
        }
        printf("]\n");
    }

    return 0;
}
