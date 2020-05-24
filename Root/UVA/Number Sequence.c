#include <stdio.h>
#include <string.h>

char arr[2147483640];

int main()
{
    long int n,m,i,j,k,len;
    char p[100];
    arr[0]='1';
    for(i=1,j=0;j<2147483647;i++)
    {
       /* len=sprintf(p,"%ld",i);
        for(k=0;k<len && j<2147483647;k++)
        {
            arr[j++]=p[k];
        }*/
    }
    return 0;
}
