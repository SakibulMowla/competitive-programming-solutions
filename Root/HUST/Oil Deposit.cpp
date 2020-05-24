#include <stdio.h>
#include <string.h>

int r,c;
char arr[110][110];
int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};
void DFS(int n,int m)
{
    arr[n][m] = '*';
    int i,u,v;
    for(i=0;i<8;i++)
    {
        u = x[i] + n;
        v = y[i] + m;
        if(u>=0 && v>=0 && u<r && v<c && arr[u][v] == '@')
            DFS(u,v);
    }
}

int main()
{
    int i,j,cnt;
    char z;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&r,&c) == 2 && r && c)
    {
        for(i=0; i<r; i++)
            scanf("%s",arr[i]);
        cnt = 0;
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                if(arr[i][j] == '@')
                {
                    cnt++;
                    DFS(i,j);
                }
            }
        printf("%d\n",cnt);
    }

    return 0;
}
