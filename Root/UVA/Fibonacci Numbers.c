#include <stdio.h>
#include <string.h>

typedef struct{
    char fib[1200];
}data ;

data arr[5010];

int main()
{
    char fn[1200],fn_1[1200],inter1[1200],inter2[1200];
    int n,m,i,j,k,l,sum,len,len1,add1,add2,c,d,car;

    fn_1[0]='0';
    arr[0].fib[0]='0';
    fn_1[1]='\0';
    arr[0].fib[1]='\0';
    fn[0]=arr[1].fib[0]='1';
    fn[1]=arr[1].fib[1]='\0';
    for(i=2; i<=5000; i++)
    {
        len=strlen(fn);
        len1=strlen(fn_1);
        car=0;
        c=0;
        for(j=len-1,k=len1-1; j>=0; j--,k--)
        {
            if(fn[j]>='0' && fn[j]<='9')
                add1=fn[j]-'0';
            else
                add1=0;
            if(fn_1[k]>='0' && fn_1[k]<='9')
                add2=fn_1[k]-'0';
            else
                add2=0;
            sum=car+add1+add2;
            car=sum/10;
            inter1[c++]=(sum%10)+'0';
        }
        if(car>0)
        {
            inter1[c++]=car+'0';
            inter1[c]='\0';
        }
        else
            inter1[c]='\0';
        d=c;
        for(k=0,j=d-1; j>=0; j--,k++)
            inter2[k]=inter1[j];
        inter2[k]='\0';
        strcpy(fn_1,fn);
        strcpy(fn,inter2);
        strcpy(arr[i].fib,inter2);
    }

    while(scanf("%d",&n)==1)
    {
        printf("%s\n",arr[n].fib);
    }

    return 0;
}
