#include <stdio.h>

#define max 10000010

int soja[max];
int ulta[max];

int main()
{
    int i,j,k,pos;

    k=1;

    for(i=1;k<max;i+=2)
    {
        for(j=1;j<=i && k<max;j++)
            soja[k++]=j;
        for(j=i-1;j>0 && k<max;j--)
            soja[k++]=j;
    }

    k=1;

    for(i=2;k<max;i+=2)
    {
        for(j=1;j<=i && k<max;j++)
            ulta[k++]=j;
        for(j=i-1;j>0 && k<max;j--)
            ulta[k++]=j;
    }

    while(scanf("%d",&pos)==1)
    {
        printf("TERM %d IS %d/%d\n",pos,soja[pos],ulta[pos]);
    }

    return 0;
}
