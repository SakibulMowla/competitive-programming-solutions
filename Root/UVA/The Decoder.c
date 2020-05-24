#include<stdio.h>
#include<string.h>

int main()
{
    char arr[100],z;
    int i,len;
    while(gets(arr))
    {
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            z=arr[i]-7;
            printf("%c",z);
        }
        printf("\n");
    }
    return 0;
}
