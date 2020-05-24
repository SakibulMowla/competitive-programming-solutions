#include "stdio.h"
#include "string.h"

char song[20][10] = {"Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia",

                     "Happy","birthday","to","you"};

int main()
{
    int i,j,n,flag;
    char arr[110][110];
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%s",arr[i]);
    flag = 1;
    j = 0;
    while(flag)
    {
        for(i=0;i<16;i++)
        {
            printf("%s: %s\n",arr[j],song[i]);
            if(j == n-1) flag = 0;
            j++;
            j %= n;
        }
    }

    return 0;
}
