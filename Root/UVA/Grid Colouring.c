#include <stdio.h>
#include <string.h>

int i,len[40];
char h,z;
void func(int n,int m,char arr[40][90]);
int main()
{
    int n,m,j,k,l;
    char arr[40][90];
    i=0;
    while(gets(arr[i]))
    {
        len[i]=strlen(arr[i]);
        for(k=0; k<len[i]; k++)
        {
            if(arr[i][k]!='_')
                break;
        }
        m=0;

        if(len[i]==k && len[i]>0)
        {
            for(j=0; j<=i; j++)
            {
                for(k=0; k<len[j]; k++)
                {
                    if(arr[j][k]!=' ')
                    {
                        h=arr[j][k];
                        m=1;
                        break;
                    }
                }
                if(m==1) break;
            }
            for(j=0; j<i; j++)
            {
                for(k=0; k<len[j]; k++)
                {
                    if(arr[j][k]!=' ' && arr[j][k]!=h)
                    {
                        z=arr[j][k];
                        func(j,k,arr);
                    }
                }
            }
            for(j=0;j<=i;j++)
                printf("%s\n",arr[j]);
            memset(arr,0,sizeof arr);
            memset(len,0,sizeof len);
            z=' ';
            i=-1;
        }
        i++;
    }

    return 0;
}

void func(int n,int m,char arr[40][90])
{
    if(n<0 || m<0 || n>i || m>=len[n])
        return;
    if(arr[n][m-1]==' ')
    {
        arr[n][m-1]=z;
        func(n,m-1,arr);
    }
    if(arr[n][m+1]==' ')
    {
        arr[n][m+1]=z;
        func(n,m+1,arr);
    }
    if(arr[n-1][m]==' ')
    {
        arr[n-1][m]=z;
        func(n-1,m,arr);
    }
    if(arr[n+1][m]==' ')
    {
        arr[n+1][m]=z;
        func(n+1,m,arr);
    }

    return;
}
