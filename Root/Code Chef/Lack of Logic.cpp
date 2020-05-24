#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"

char arr[1000],ch;
int mark[100];

int main()
{
    int t,i,j,k,n;
    while(scanf("%d",&t) == 1)
    {
        while(t--)
        {
            scanf(" %[^\n]",arr);
            memset(mark,0,sizeof(mark));
            for(i=0;arr[i];i++)
            {
                ch = tolower(arr[i]);
                if(ch>='a' && ch<='z')
                mark[ch-'a'] = 1;
            }
            j = 0;
            for(i=0;i<26;i++)
                j += mark[i];
            if(j == 26)
            {
                printf("~\n");
                continue;
            }
            for(i=0;i<26;i++)
            {
                if(mark[i] == 0)
                {
                    printf("%c\n",i+'a');
                    break;
                }
            }
        }
    }

    return 0;
}
