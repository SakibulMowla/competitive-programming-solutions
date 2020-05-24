#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,n,k,len,m;
    char z,arr[110][110];

    memset(arr,' ',sizeof(arr));

    i=0;
    m=0;
    while(gets(arr[i]))
    {
        len=strlen(arr[i]);
        if(len>m)
            m=len;
        arr[i][len]=' ';
        i++;
    }
    for(j=0; j<m; j++)
    {
        for(k=i-1; k>=0; k--)
        {
            printf("%c",arr[k][j]);
        }
        printf("\n");
    }

    return 0;
}
