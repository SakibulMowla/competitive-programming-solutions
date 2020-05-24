#include <stdio.h>
#include <string.h>

char arr[1000000+10];

int main()
{
    int i,j,k,len;
    while(scanf("%s",arr)==1)
    {
        if(strcmp(arr,".")==0) break;
        len=strlen(arr);
        i=1;
        for(j=0; j<len/2; j++)
        {
            if(arr[j+1]==arr[0] && (len % (j+1))==0)
            {
                for(k=j+1;k<len;k++)
                {
                    if(arr[k]!=arr[k%(j+1)]) break;
                }
                if(k==len)
                {
                    i=len/(j+1);
                    break;
                }
            }
        }

        printf("%d\n",i);
    }
    return 0;
}
