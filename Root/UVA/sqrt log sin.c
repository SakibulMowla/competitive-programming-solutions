#include <stdio.h>
#include <string.h>
#include <math.h>

#define max 1000001

int x[max];

int main()
{
    x[0]=1;
    int n,i;

    for(i=1;i<max;i++)
    {
        x[i]=( x[(int)(i-sqrt(i))] + x[(int)log(i)] + x[(int)(i*sin(i)*sin(i))] ) % 1000000;
    }

    while(scanf("%d",&n) && n!=-1)
    {
        printf("%d\n",x[n]);
    }

    return 0;
}
