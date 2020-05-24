#include<stdio.h>
#include<string.h>

int main()
{
    char a[1000],b[1000],add[1000];
    int n,m,i,j,l,k,len,len1,add1,add2;
    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0;n>0;i++,n/=2)
            a[i]=(n%2)+'0';
        for(j=0;m>0;j++,m/=2)
            b[j]=(m%2)+'0';
        len=strlen(a);len1=strlen(b);printf("%d\t%d\n",len,len1);
        if(len>=len1)
            j=len-1;
        else
            j=len1-1;
        for(k=j,i=len-1,l=len1-1;k>=0;k--,i--,l--)
        {
            if(a[i]>='0' && a[i]<='9')add1=a[i]-'0';
            else add1=0;
            if(b[l]>='0' && b[l]<='9')add2=b[l]-'0';
            else add2=0;
            add[k]=add1+add2+'0';
        }
        printf("%s\n",add);
    }
    return 0;
}
