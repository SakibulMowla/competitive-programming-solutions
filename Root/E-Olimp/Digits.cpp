#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char arr[100];
    while(scanf("%d",&n) == 1)
    {
        printf("%d\n",sprintf(arr,"%d",n));
    }
    return 0;
}
