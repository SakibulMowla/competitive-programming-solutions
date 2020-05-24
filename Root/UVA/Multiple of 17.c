#include <stdio.h>
#include <string.h>

int main()
{
    char arr[1000];
    int i,len,sum;
    while(scanf("%s",arr)==1)
    {
        len=strlen(arr);
        if(len==1 && arr[0]=='0')
            break;
        sum=0;
        for(i=0;i<len;i++)
        {
            sum=((sum*10)+(arr[i]-'0'))%17;
        }
        if(sum==0)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
