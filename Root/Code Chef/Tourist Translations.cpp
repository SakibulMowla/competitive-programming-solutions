#include "stdio.h"
#include "string.h"

char map[300],arr[110];

int main()
{
    int i,j,n;
    while(scanf("%d %s",&n,arr) == 2)
    {
        for(i=0;arr[i];i++)
            map[i+(int)'a'] = arr[i] , map[i+(int)'A'] = arr[i] - 32;
        for(i=0;i<n;i++)
        {
            scanf("%s",arr);
            for(j=0;arr[j];j++)
            {
                if((arr[j] >= 'A' && arr[j] <= 'Z') || (arr[j] >= 'a' && arr[j] <= 'z'))
                    printf("%c",map[arr[j]]);
                else if(arr[j] == '_')
                    printf(" ");
                else printf("%c",arr[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
