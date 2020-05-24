#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

int cnt[35];

int main()
{
    char arr[110] , ch;
    int n,i,j,k;
    j = 0;
    while(scanf(" %[^\n]",arr) == 1)
    {
        if(arr[0] == '#')
        {
            for(i=1;i<35;i++)
            {
                if(cnt[i]) printf("%d %d\n",i,cnt[i]);
                cnt[i] = 0;
            }
            printf("\n");
        }
        n = strlen(arr);
        for(i=0;i<n;i++)
        {
            if(arr[i]==' ' || arr[i]=='?' || arr[i]=='!' || arr[i]==',' || arr[i]=='.' )
                cnt[j]++ , j = 0;
            else if(isalpha(arr[i])) j++;
        }
        if(arr[n-1] != '-') cnt[j]++ , j = 0;
    }

    return 0;
}
