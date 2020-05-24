#include <stdio.h>
#include <string.h>

char h,ch,arr[210][210];
int n;
void func(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=n)
        return;
    if(h=='w' && j==n-1)
    {
        ch='W';
        return;
    }
    if(h=='b' && i==n-1)
    {
        ch='B';
        return;
    }
    if(arr[i-1][j-1]==h)
    {
        arr[i-1][j-1]='0';
        func(i-1,j-1);
    }
    if(arr[i-1][j]==h)
    {
        arr[i-1][j]='0';
        func(i-1,j);
    }
    if(arr[i][j-1]==h)
    {
        arr[i][j-1]='0';
        func(i,j-1);
    }
    if(arr[i][j+1]==h)
    {
        arr[i][j+1]='0';
        func(i,j+1);
    }
    if(arr[i+1][j]==h)
    {
        arr[i+1][j]='0';
        func(i+1,j);
    }
    if(arr[i+1][j+1]==h)
    {
        arr[i+1][j+1]='0';
        func(i+1,j+1);
    }
}
int main()
{
    int i,k;
    char z;
    k=1;
    while(scanf("%d%c",&n,&z)==2 && n)
    {
        for(i=0;i<n;i++)
            gets(arr[i]);
        ch='n';
        for(i=0;i<n;i++)
        {
            if(arr[0][i]=='b')
            {
                h='b';
                arr[0][i]='0';
                func(0,i);
                if(ch=='B')
                {
                    printf("%d B\n",k);
                    break;
                }
            }
            else if(arr[i][0]=='w')
            {
                h='w';
                arr[i][0]='0';
                func(i,0);
                if(ch=='W')
                {
                    printf("%d W\n",k);
                    break;
                }
            }
        }
        memset(arr,0,sizeof arr);
        k++;
    }

    return 0;
}
