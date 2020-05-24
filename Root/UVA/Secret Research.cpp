#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "iostream"

using namespace std;



int main()
{
    int n, len;
    char arr[1010];

    scanf("%d",&n);

    while(n--)
    {
        scanf("%s",arr);
        len = strlen(arr);

        if(strcmp(arr,"1") == 0 || strcmp(arr,"4") == 0 || strcmp(arr,"78") == 0)
            printf("+\n");
        else if(arr[len-1] == '5' && arr[len-2] == '3')
            printf("-\n");
        else if(arr[0] == '9' && arr[len-1] == '4')
            printf("*\n");
        else if(arr[0] == '1' && arr[1] == '9' && arr[2] == '0')
            printf("?\n");
    }

    return 0;
}










