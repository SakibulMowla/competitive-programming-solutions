#include "stdio.h"

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n == 0) printf("0\n");
        else if(n%5 == 0 && n%7 == 0)
            printf("fizzbuzz\n");
        else if(n%5 == 0)
            printf("fizz\n");
        else if(n%7 == 0)
            printf("buzz\n");
        else printf("%d\n",n);
    }

    return 0;
}
