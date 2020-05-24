#include <stdio.h>
#include <string.h>

char arr[100000008];
int main()
{
    long n,m,j,i,k,l;
    char p[10];
    arr[0]='0';
    k=1;
    for(i=1;; i++)
    {
        l=sprintf(p,"%ld",i);
        for(j=0; j<l; j++)
        {
            if(k==100000001)
                break;
            arr[k++]=p[j];
        }
        if(k==100000001)
                break;
    }
    while(scanf("%d",&n)==1)
        printf("%c\n",arr[n]);
    return 0;
}
