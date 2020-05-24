/*
ID: sakibul1
PROG: satpix
LANG: C++
*/
#include "stdio.h"
#include "string.h"

#define SS(n) scanf("%s",n)

char arr[1010][85];
int r,c,cnt;

int x[] = {1,-1,0,0};
int y[] = {0,0,1,-1};

void dfs(int n,int m)
{
    cnt++;
    arr[n][m] = '.';
    int i,v,u;
    for(i=0;i<4;i++)
    {
        u = n + x[i];
        v = m + y[i];
        if(u>=0 && v>=0 && u<r && v<c && arr[u][v] == '*') dfs(u,v);
    }
}

int main()
{
    freopen("satpix.in","r",stdin);
    freopen("satpix.out","w",stdout);
    int i,j,k,maxcnt = 0;
    scanf("%d %d",&c,&r);
    for(i=0;i<r;i++) SS(arr[i]);
    for(i=0;i<r;i++) for(j=0;j<c;j++)
    {
        if(arr[i][j] == '*')
        {
           cnt=0;
           dfs(i,j);
           if(cnt > maxcnt) maxcnt = cnt;
        }
    }

    printf("%d\n",maxcnt);

    return 0;
}
