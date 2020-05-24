#include <stdio.h>
#include <string.h>

int r,c,count;
void func(int n,int m,char arr[30][30]);
int main()
{
    int i,j,k,l,n,m;
    char arr[30][30],z;

    scanf("%d",&n);
    for(k=0; k<n; k++)
    {
        l=0;count=0;
        scanf("%d %d%c",&c,&r,&z);
        for(i=0;i<r;i++)
            gets(arr[i]);

        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(arr[i][j]=='@')
                {
                    count++;
                    func(i,j,arr);
                    l=1;
                    break;
                }
            }
            if(l==1)
                break;
        }
        printf("Case %d: %d\n",k+1,count);
        memset(arr,0,sizeof arr);
    }
    return 0;
}

void func(int n,int m,char arr[30][30])
{
    if(n<0 || m<0 || n>=r || m>=c)
        return;
    if(arr[n-1][m]=='.')
    {
        count++;
        arr[n-1][m]='0';
        func(n-1,m,arr);
    }
    if(arr[n+1][m]=='.')
    {
        count++;
        arr[n+1][m]='0';
        func(n+1,m,arr);
    }
    if(arr[n][m-1]=='.')
    {
        count++;
        arr[n][m-1]='0';
        func(n,m-1,arr);
    }
    if(arr[n][m+1]=='.')
    {
        count++;
        arr[n][m+1]='0';
        func(n,m+1,arr);
    }
    return;
}
