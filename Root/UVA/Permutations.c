#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 22

char arr[max];
long long per[max];

int cmp(const void *a,const void *b){ return( *(char*)a -*(char*)b ); }

void swap(char *a,char*b)
{
    char c;
    c=*a;
    *a=*b;
    *b=c;
    return;
}

void permute(char *line,long long target,int len)
{
    qsort(line,len,sizeof(char),cmp);
    long long d,i;

    if(target==0)
        return;

    for(i=0,d=0; i<=len && per[len-1]*i<=target ;i++)
        d=per[len-1]*i;

    swap(line,line+i-1);
    permute(line+1,target-d,len-1);

    return;
}

int main()
{
    int k,p,len;
    long long n,i;

    for(per[0]=1,i=1;i<max;i++)
        per[i]=per[i-1]*i;

    scanf("%d",&k);
    for(p=0;p<k;p++)
    {
        scanf("%s %lld",arr,&n);
        len=strlen(arr);
        permute(arr,n,len);

        printf("%s\n",arr);
    }
    return 0;
}
