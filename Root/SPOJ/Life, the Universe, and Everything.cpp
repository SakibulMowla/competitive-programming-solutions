#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=42)
        printf("%d\n",n);
    return 0;
}
