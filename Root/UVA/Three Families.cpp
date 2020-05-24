#include <stdio.h>

int main()
{
    int n,x,y,z;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d",&x,&y,&z);
        printf("%d\n",z * (2 * x - y) / (x + y));
    }

    return 0;
}
