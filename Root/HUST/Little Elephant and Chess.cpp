#include "stdio.h"
char arr[10];

int main()
{
    int i,j,k;
    for(i=0;i<8;i++)
    {
        scanf("%s",arr);
        for(j=0;j<7;j++)
            if(arr[j] == arr[j+1])
            {
                printf("NO");
                return 0;
            }
    }
    printf("YES");

    return 0;
}
