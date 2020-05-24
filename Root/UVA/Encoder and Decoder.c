#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,len;
    char arr[300];
    while(gets(arr))
    {
        len=strlen(arr);

        if(arr[0]>='0' && arr[0]<='9')
        {
            for(i=len-1;i>=0;i--)
            {
                n=arr[i] - '0';
                n=(n*10) + (arr[--i] - '0');

                if(n<32)
                n=(n*10) + (arr[--i] - '0');

                printf("%c",n);
            }
            printf("\n");
        }

        else
        {
            for(i=len-1;i>=0;i--)
            {
                n=arr[i];
                do{
                    printf("%d",n%10);
                } while(n/=10);
            }
            printf("\n");
        }
    }
    return 0;
}
