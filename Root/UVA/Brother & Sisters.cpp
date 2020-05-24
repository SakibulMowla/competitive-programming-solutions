#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int i,a,b;
    while(scanf("%d",&a) == 1)
    {
        for(i=0; i<10; i++)
        {
            printf("%d\n",i&a);
        }
    }

    return 0;
}
