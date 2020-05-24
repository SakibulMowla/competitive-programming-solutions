#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
    int t,test,i;
    char arr[1010] , *str , ans[200];
    scanf("%d",&test);
    getchar();
    getchar();
    for(t=1; t<=test; t++)
    {
        if(t>1) printf("\n");
        printf("Case #%d:\n",t);

        while(gets(arr))
        {
            i = 0;
            if(strcmp(arr,"\0") == 0) break;
            str = strtok(arr," ");

            while(str)
            {
                if(strlen(str) > i)
                {
                    ans[i] = str[i];
                    i++;
                }
                str = strtok(NULL , " ");
            }
            ans[i] = '\0';
            printf("%s\n",ans);
        }
    }

    return 0;
}
