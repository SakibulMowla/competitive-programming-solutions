#include "stdio.h"
#include "string.h"
#include "ctype.h"

char arr[110];

bool check(char ch)
{
    ch = tolower(ch);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') return 1;
    return 0;
}

int main()
{
    int i,j,k;

    while(scanf("%s",arr) == 1)
    {
        for(i=0;arr[i];i++)
        {
            if(check(arr[i])) continue;
            printf(".%c",tolower(arr[i]));
        }
        printf("\n");
    }

    return 0;
}
