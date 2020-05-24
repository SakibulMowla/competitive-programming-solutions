#include "stdio.h"
#include "string.h"
#include "math.h"

int main()
{
    int i,arr[80];
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 2;
    for(i=4;i<80;i++)
        arr[i] = arr[i-2] + arr[i-3];
    while(scanf("%d",&i)==1)
        printf("%d\n",arr[i]);

    return 0;
}
