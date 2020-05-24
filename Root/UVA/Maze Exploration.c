#include <stdio.h>
#include <string.h>

int r,c,mp[40];
void func(int n,int m,char arr[40][90]);
int main()
{
    int i,j,k,l,n;
    char arr[40][90],z,str[90];
    scanf("%d%c",&n,&z);
    for(l=0; l<n; l++)
    {
        r=0;
        while(gets(str))
        {
            mp[r]=strlen(str);
            strcpy(arr[r++],str);
            for(k=0; k<strlen(str); k++)
            {
                if(str[k]!='_')
                    break;
            }
            if(k==strlen(str)) break;
        }
        if(k==strlen(str))
        {
            for(i=0; i<r; i++)
            {
                for(j=0; j<mp[i]; j++)
                {
                    if(arr[i][j]=='*')
                    {
                        arr[i][j]='#';
                        func(i,j,arr);
                    }
                }
            }
            for(i=0; i<r; i++)
                printf("%s\n",arr[i]);
            memset(arr,0,sizeof arr);
            memset(mp,0,sizeof mp);
        }
    }

    return 0;
}

void func(int n,int m,char arr[40][90])
{
    if(n<0 || m<0 || n>=r || m>=mp[n])
        return;

    if(arr[n][m-1]==' ')
    {
        arr[n][m-1]='#';
        func(n,m-1,arr);
    }
    if(arr[n][m+1]==' ')
    {
        arr[n][m+1]='#';
        func(n,m+1,arr);
    }
    if(arr[n-1][m]==' ')
    {
        arr[n-1][m]='#';
        func(n-1,m,arr);
    }
    if(arr[n+1][m]==' ')
    {
        arr[n+1][m]='#';
        func(n+1,m,arr);
    }
    return;
}
