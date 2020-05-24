#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,arr[60];
    memset(arr,0,sizeof arr);
    for(i=0;i<60;i++)
        printf("%d\n",arr[i]);

    return 0;
}
