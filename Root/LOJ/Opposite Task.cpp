#include <stdio.h>

int main()
{
    int n,t,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a = 0;
        if(n>10) a = n - 10 , n = 10;
        printf("%d %d\n",a,n);
    }

    return 0;
}
