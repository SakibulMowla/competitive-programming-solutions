#include<stdio.h>
#include<string.h>

typedef struct {
        char num[1000];
        int d;
}data;
int main()
{
    data arr[1000];
    int i,j,k,l,n,m,len,sum,car;
    char add[1000];
    len=0;
    for(i=0;;i++)
    {
        gets(arr[i].num);
        l=strlen(arr[i].num);
        arr[i].d=l;
        if(l>len)
            len=l;
        if(l==1 && arr[i].num[0]=='0')
            break;
    }
    k=i;car=0;
    for(j=0;j<len;j++)
    {
        sum=car;
        for(n=0;n<k;n++)
        {
            m=arr[n].d;
            if(arr[n].num[m-1]>='0' && arr[n].num[m-1]<='9')
            sum+=(arr[n].num[m-1])-'0';
            --arr[n].d;
        }
        add[j]=(sum%10)+'0';
        car=sum/10;
    }
    if(car>0)
        printf("%d",car);
    for(i=len-1;i>=0;i--)
        printf("%c",add[i]);
    printf("\n");

    return 0;
}
