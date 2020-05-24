#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,len;
    char arr[100000],ch;
    while(scanf(" %c %s",&ch,arr)==2)
    {
        len=strlen(arr);
        if(ch=='0' && len==1 && arr[0]=='0') break;
        j=0;
        for(i=0;i<len;i++)
        {
            if(arr[i]!=ch)
            {
                if(arr[i]!='0')
                    j=1;
                if(j==1)
                    printf("%c",arr[i]);
            }
        }
        if(j==0)
            printf("0");
        printf("\n");
    }
    return 0;
}
