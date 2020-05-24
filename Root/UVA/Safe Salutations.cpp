// Catalan Numbers
//C(0) = 1 && C(n+1) = C(n) * 2 * (2n + 1) / (n + 2)
#include "stdio.h"
#include "math.h"


int main()
{
    int arr[12],i,c=0;
    arr[0] = 1;
    for(i=0; i<=10; i++)
        arr[i+1] = ( arr[i] * 2 * ((2 * i) + 1) ) / (i + 2);
    while(scanf("%d",&i) == 1)
    {
        if(c) printf("\n");
        c=1;
        printf("%d\n",arr[i]);
    }

    return 0;
}
