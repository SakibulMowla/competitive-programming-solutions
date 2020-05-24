#include "stdio.h"
int t,n,i;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&i);
        if(i > 0) t += i;
    }
    printf("%d\n",t);
    return 0;
}
