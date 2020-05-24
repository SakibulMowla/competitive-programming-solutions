#include "stdio.h"
#include "math.h"

int main()
{
    int n;
    scanf("%d",&n);
    if(n < 1)
    {
        n *= -1;
        n = -(n*(n+1))/2 + 1;
    }
    else
        n = (n*(n+1))/2;
    printf("%d\n",n);

    return 0;
}
