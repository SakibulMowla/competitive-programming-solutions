#include<stdio.h>
#include<string.h>

int main()
{
    char arr[1000];
    int i,j,len,c;
    while(gets(arr))
    {
        c=0;
        len = strlen(arr);
        for(i=0;i<len;i++)
        {
            if(arr[i]==' ' && c==0)
            {
                for(j=i-1;j>=0;j--)
                {
                    printf("%c",arr[j]);
                }
                printf(" ");c++;
            }
            else if(arr[i]==' ' && c!=0)
            {
                for(j=i-1;arr[j]!=' ';j--)
                {
                    printf("%c",arr[j]);
                }
                printf(" ");
            }
            else if(i==len-1 && c!=0)
            {
                for(j=i;arr[j]!=' ';j--)
                    printf("%c",arr[j]);
            }
            else if(i==len-1 && c==0)
            {
                for(j=i;j>=0;j--)
                    printf("%c",arr[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
