#include <stdio.h>
#include <string.h>

int main()
{
    int M , F , test , n;
    char *str,arr[1000];
    scanf("%d",&test);
    while(test--)
    {
        scanf(" %[^\n]",arr);
        M = F = n = 0;
        str = strtok(arr," ");
        while(str)
        {
            n++;
            if(str[0] == 'M') M++;
            if(str[1] == 'M') M++;
            if(str[0] == 'F') F++;
            if(str[1] == 'F') F++;
            str = strtok(NULL," ");
        }
        if(n>1 && M==F) printf("LOOP\n");
        else printf("NO LOOP\n");
    }

    return 0;
}
