#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char line[100];
    int i,j,k,len,maxcnt,cnt[30];
    bool blank;
    while(scanf(" %[^\n]",line) == 1)
    {
        memset(cnt,0,sizeof(cnt));
        maxcnt = 0;
        len = strlen(line);
        for(i=0; i<len; i++)
        {
            if(line[i] >='A' && line[i] <= 'Z')
            {
                cnt[line[i]-'A']++;
                if(cnt[line[i]-'A'] > maxcnt)   maxcnt = cnt[line[i]-'A'];
            }
        }
        for(j=0; j<3; j++)
        {
            scanf(" %[^\n]",line);
            len = strlen(line);
            for(i=0; i<len; i++)
            {
                if(line[i] >='A' && line[i] <= 'Z')
                {
                    cnt[line[i]-'A']++;
                    if(cnt[line[i]-'A'] > maxcnt)   maxcnt = cnt[line[i]-'A'];
                }
            }
        }

        for(i=maxcnt;i>0;i--)
        {
            blank = false;
            for(j=0;j<26;j++)
            {
                if(blank) printf(" ");
                blank = true;
                if(cnt[j] >= i)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        blank = false;
        for(i='A';i<='Z';i++)
        {
            if(blank) printf(" ");
            blank = true;
            printf("%c",i);
        }
        printf("\n");
    }

    return 0;
}
