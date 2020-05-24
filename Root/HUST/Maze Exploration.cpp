#include "stdio.h"
#include "string.h"

int r,col[40];
char arr[40][90];

int x[]= {-1,1,0,0};
int y[]= {0,0,-1,1};

void DFS(int n,int m)
{
    arr[n][m] = '#';
    int i,u,v;
    for(i=0;i<4;i++)
    {
        u = n + x[i];
        v = m + y[i];
        if(u>=0 && v>=0 && u<r && v<col[u] && arr[u][v] == ' ')
            DFS(u,v);
    }
}

int main()
{
    int test,i,j;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        r = 0;
        while(scanf(" %[^\n]",arr[r]) == 1)
        {
            col[r] = strlen(arr[r]);
            for(i=0;i<col[r];i++)
                if(arr[r][i] != '_')
                    break;
            r++;
            if(i == col[r-1])
                break;
        }
        for(i=0;i<r;i++)
            for(j=0;j<col[i];j++)
                if(arr[i][j] == '*')
                    DFS(i,j);
        for(i=0;i<r;i++)
            printf("%s\n",arr[i]);
    }

    return 0;
}
