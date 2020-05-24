#include <stdio.h>
#include <string.h>

int r,c,count;
char l;
void func(int n,int m,char arr[30][30]);
int main()
{
    int n,m,i,j,max_count;
    char z,arr[30][30];
    while(scanf("%d %d%c",&r,&c,&z)==3)
    {
        for(i=0;i<r;i++)
            scanf("%s",arr[i]);
        scanf("%d %d",&m,&n);
        l=arr[m][n];
        func(m,n,arr);
        max_count=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j]==l)
                {
                    count=0;
                    arr[i][j]='0';
                    count++;
                    func(i,j,arr);
                    if(count>max_count)
                        max_count=count;
                }
            }
        }
        printf("%d\n",max_count);
        memset(arr,0,sizeof arr);
    }

    return 0;
}

void func(int n,int m,char arr[30][30])
{
    if(n<0 || m<0 || n>=r || m>=c)
        return;
    if(m==c-1 && arr[n][0]==l)
    {
        count++;
        arr[n][0]='0';
        func(n,0,arr);
    }
    if(m==0 && arr[n][r-1]==l)
    {
        count++;
        arr[n][r-1]='0';
        func(n,r-1,arr);
    }
    if(arr[n][m-1]==l)
    {
        count++;
        arr[n][m-1]='0';
        func(n,m-1,arr);
    }
    if(arr[n][m+1]==l)
    {
        count++;
        arr[n][m+1]='0';
        func(n,m+1,arr);
    }
    if(arr[n-1][m]==l)
    {
        count++;
        arr[n-1][m]='0';
        func(n-1,m,arr);
    }
    if(arr[n+1][m]==l)
    {
        count++;
        arr[n+1][m]='0';
        func(n+1,m,arr);
    }
    return;
}
