#include <stdio.h>
#include <string.h>

#define max 100010

char arr[max],str[max],beiju[100000][10000];
int main()
{
    int i,k,l,p,len,count;

    while(gets(arr))
    {
        len=strlen(arr);
        count=0;l=0;k=0;p=0;
        for(i=0;i<len;i++)
        {
            if(count>0 && arr[i]=='[')
            {
                beiju[k][p]='\0';
                ++k;
                p=0;
                continue;
            }
            else if(arr[i]=='[')
            {
                ++count;
                continue;
            }
            else if(arr[i]==']' && count>0)
            {
                --count;
                beiju[k][p]='\0';
                ++k;
                p=0;
                continue;
            }


            else if(count > 0)
            {
                beiju[k][p++]=arr[i];
            }

            else
            {
                if(arr[i]!='[' && arr[i]!=']')
                {
                    str[l++]=arr[i];
                }
            }
        }
        str[l]='\0';
        if(count>0)
            beiju[k][p]='\0';
        for(i=k;i>=0;i--)
            printf("%s",beiju[i]);
        printf("%s",str);
        printf("\n");
    }
    return 0;
}
