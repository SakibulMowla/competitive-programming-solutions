#include <stdio.h>
#include <string.h>

int r,c,count[200];
char h;
void func(int n,int m,char arr[100][100]);
int main()
{
    int n,m,i,j,k,l,max_count;
    char arr[100][100],z;
    scanf("%d",&n);
    for(l=1;l<=n;l++)
    {
        scanf("%d %d%c",&r,&c,&z);
        for(i=0;i<r;i++)
            gets(arr[i]);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j]>='a' && arr[i][j]<='z')
                {
                    count[arr[i][j]]++;
                    h=arr[i][j];
                    arr[i][j]='0';
                    func(i,j,arr);
                }
            }
        }
        max_count=0;
        for(i=90;i<130;i++)
        {
            if(count[i]>max_count)
                max_count=count[i];
        }
        printf("World #%d\n",l);
        for(i=max_count;i>0;i--)
        {
            for(j=90;j<130;j++)
            {
                if(i==count[j])
                    printf("%c: %d\n",j,i);
            }
        }
        memset(arr,0,sizeof arr);
        memset(count,0,sizeof count);
    }
    return 0;
}

void func(int n,int m,char arr[100][100])
{
    if(n<0 || m<0 || n>=r || m>=c)
        return;
    if(arr[n-1][m]==h)
    {
        arr[n-1][m]='0';
        func(n-1,m,arr);
    }
    if(arr[n+1][m]==h)
    {
        arr[n+1][m]='0';
        func(n+1,m,arr);
    }
    if(arr[n][m-1]==h)
    {
        arr[n][m-1]='0';
        func(n,m-1,arr);
    }
    if(arr[n][m+1]==h)
    {
        arr[n][m+1]='0';
        func(n,m+1,arr);
    }

    return;
}
