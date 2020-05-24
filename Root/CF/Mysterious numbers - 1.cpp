#include "stdio.h"

int main()
{
    int i,j,k;
    while(scanf("%d %d",&i,&j) == 2)
    {
        k = 0;
        while(j)
        {
            k = (k*10) + (j%10);
            j /= 10;
        }
        printf("%d\n",i+k);
    }

    return 0;
}
