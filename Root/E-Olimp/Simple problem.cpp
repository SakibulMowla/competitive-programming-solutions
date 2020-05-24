#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
        printf("%d %d\n",n/10,n%10);

    return 0;
}
