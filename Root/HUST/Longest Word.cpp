#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"


#define SZ 210


int main()
{
    char arr[SZ], tmp[SZ], best[SZ];
    int i, j, k, l = 0;


    while(scanf("%s",arr) == 1)
    {
        if(strcmp(arr,"E-N-D") == 0) break;

        k = strlen(arr);
        j = 0;

        for(i=0;i<k;i++)
        {
            if( (tolower(arr[i])>='a' && tolower(arr[i]) <= 'z') || arr[i] == '-' )
                tmp[j++] = tolower(arr[i]);
            tmp[j] = '\0';
            if(strlen(tmp) > l)
            {
                l = strlen(tmp);
                strcpy(best, tmp);
            }
        }
    }

    printf("%s\n",best);


    return 0;
}

