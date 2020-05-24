#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void func(int i,int j,char arr[110][110]);
int r,c;
int main()
{
    int count,i,j,k,l,n,m;
    char arr[110][110],z;

    while(scanf("%d %d%c",&r,&c,&z)==3)
    {
        if(r==0)
            break;
        for(i=0;i<r;i++)
            gets(arr[i]);
        count=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j]=='@')
                {
                    count++;
                    func(i,j,arr);
                }
            }
        }
        printf("%d\n",count);
    }

    return 0;
}

void func(int i,int j,char arr[110][110])
{
    int n,m;
    if(i<0 || i>=r || j<0 || j>=c)
        return;
    arr[i][j]='*';
    for(n=i-1;n<=i+1;n++)
    {
        for(m=j-1;m<=j+1;m++)
        {
            if(arr[n][m]=='@')
                func(n,m,arr);
        }
    }
    return;
}
