#include <stdio.h>
#include <string.h>

int main()
{
    char arr[100];
    int t = 0;
    while(scanf("%s",arr) == 1)
    {
        if(strcmp(arr,"*") == 0) break;
        if(strcmp(arr,"Hajj") == 0) printf("Case %d: Hajj-e-Akbar\n",++t);
        if(strcmp(arr,"Umrah") == 0) printf("Case %d: Hajj-e-Asghar\n",++t);
    }

    return 0;
}
