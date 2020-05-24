#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,k,l,n,m,sum;
    char ch;
    sum=0;
    while(scanf("%c",&ch)!=EOF)
    {
        if(ch=='\n' || ch=='!')
        {
            printf("\n");
            sum=0;
        }
        else if(ch >='0' && ch<='9')
        {
            sum=sum+ch-'0';
        }
        else if(ch=='b')
        {
            for(i=0;i<sum;i++)
                printf(" ");
            sum=0;
        }
        else
        {
            for(i=0;i<sum;i++)
                printf("%c",ch);
            sum=0;
        }
    }

    return 0;
}
