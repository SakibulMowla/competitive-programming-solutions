#include<stdio.h>
#include<string.h>
#define loop for(i=1; i<=n; i++)                    \
        {                                           \
            for(j=(i*l)-1; j>=(i*l)-l; j--)         \
                printf("%c",arr[j]);                \
        }                                           \
        for(i=0;i<len;i++)                          \
            arr[i]='\0';
int main()
{
    int n,i,j,k,l,len;
    char arr[1000],z;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        scanf("%c",&z);
        gets(arr);
        len=strlen(arr);
        arr[len]='\0';
        l=len/n;
        loop
        printf("\n");
    }
    return 0;
}
