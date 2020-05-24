#include "stdio.h"

int ulta(int n)
{
    int i;
    i = 0;
    while(n)
    {
        i = (i*10) + (n%10);
        n /= 10;
    }
    return i;
}

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        printf("%d\n",ulta(ulta(n)+ulta(m)));
    }

    return 0;
}
