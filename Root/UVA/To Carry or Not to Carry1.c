#include<stdio.h>
#include<string.h>

int main()
{
    char a[1000],b[1000],add[1000],c[1000],d[1000];
    int n,m,i,j,l,k,len,len1,len2,sum;
    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0; n>0; n/=2,i++)
            a[i]=(n%2)+'0';
        a[i++]='\0';
        len=strlen(a);
        for(i=0,j=len-1; j>=0; i++,j--)
            c[i]=a[j];
        c[i++]='\0';
        for(j=0; m>0; j++,m/=2)
            b[j]=(m%2)+'0';
        b[j++]='\0';
        len1=strlen(b);
        for(i=0,j=len1-1; j>=0; i++,j--)
            d[i]=b[j];
        d[i++]='\0';
        if(len>=len1)
            j=len-1;
        else
            j=len1-1;
        for(k=j,i=len-1,l=len1-1; k>=0; k--,i--,l--)
        {
            if(c[i]=='1' && d[l]=='1')
                add[k]='0';
            else if(c[i]=='1' || d[l]=='1')
                add[k]='1';
            else
                add[k]='0';
        }
        add[j+1]='\0';
        len2=strlen(add);
        sum=0;
        for(i=len2-1,j=1; i>=0; i--,j*=2)
            sum+=(add[i]-'0')*j;
        printf("%d\n",sum);
    }
    return 0;
}

