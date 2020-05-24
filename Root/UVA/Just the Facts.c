#include <stdio.h>

int main()
{
    int arr[10010],fac,i;

    arr[0] = arr[1] = 1;
    fac = 1;

    for(i=2; i<=10000; i++)
    {
        fac *= i;
        while(fac % 10 == 0)
            fac /= 10;
        fac = fac % 100000;
        arr[i] = fac%10;
    }

    while(scanf("%d",&i) == 1)
    {
        printf("%5d -> %d\n",i,arr[i]);
    }

    return 0;
}
