#include<stdio.h>
#include<string.h>

void main(void)
{
    int i,k,l;
    char arr[1001];
    while(gets(arr))
    {
        l=strlen(arr);
        if(l==1 && arr[0]=='0')
            break;
        k=0;
        for(i=0;i<l;i++)
        {
            k=((k*10)+(arr[i]-'0'))%11;
        }
        if(k==0)
            printf("%s is a multiple of 11.\n",arr);
        else
            printf("%s is not a multiple of 11.\n",arr);
    }
    return;
}
