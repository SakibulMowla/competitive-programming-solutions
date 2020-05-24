#include "stdio.h"
#include "ctype.h"
#include "string.h"
#define SZ 110


int check(char *s)
{
    int under, upper, i, n, prev;

    under = upper = 0;
    n = strlen(s);
    prev = 0;

    for(i=0; i<n; i++)
    {
        if(s[i] == '_')
        {
            if(i == 0 || i == n-1 || prev == 1) return -1;
            prev = 1;
            under++;
        }

        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            if(i == 0) return -1;
            prev = 2;
            upper++;
        }

        else
        {
            prev = 0;
        }
    }

    if((under and upper)) return -1;
    if(under) return 1;
    return 2;
}


int main()
{
    char s[SZ];
    int i, j, k;

    while(gets(s))
    {
        j = check(s);
        k = strlen(s);

        if(j == -1)
        {
            printf("Error!\n");
        }

        else if(j == 1)
        {
            for(i=0; i<k; i++)
            {
                if(s[i]== '_')
                {
                    i++;
                    printf("%c",toupper(s[i]));
                }
                else
                    printf("%c",s[i]);
            }
            printf("\n");
        }

        else
        {
            for(i=0; i<k; i++)
            {
                if(s[i] >= 'A' && s[i] <= 'Z')
                    printf("_%c",tolower(s[i]));
                else
                    printf("%c",s[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
