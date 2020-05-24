#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SZ 12

char arr[SZ][SZ];

int b_col[SZ][SZ] , w_col[SZ][SZ];

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

void dfs_black(int r,int c)
{
    int i,n,m;
    for(i=0; i<4; i++)
    {
        n = r + x[i];
        m = c + y[i];
        if(n>=0 && m>=0 && n<9 && m<9 && !b_col[n][m] && arr[n][m] == '.')
            b_col[n][m] = 1,dfs_black(n,m);
    }
}

void dfs_white(int r,int c)
{
    int i,n,m;
    for(i=0; i<4; i++)
    {
        n = r + x[i];
        m = c + y[i];
        if(n>=0 && m>=0 && n<9 && m<9 && !w_col[n][m] && arr[n][m] == '.')
            w_col[n][m] = 1,dfs_white(n,m);
    }
}

int main()
{
    int test,i,j,b_cnt,w_cnt;
    scanf("%d",&test);
    while(test--)
    {
        b_cnt = w_cnt = 0;
        for(i=0; i<9; i++)
            scanf(" %[^\n]",arr[i]);
        memset(b_col,0,sizeof(b_col));
        memset(w_col,0,sizeof(w_col));
        for(i=0; i<9; i++)
            for(j=0; j<9; j++)
                if(arr[i][j] == 'X')
                {
                    b_cnt++;
                    dfs_black(i,j);
                }
                else if(arr[i][j] == 'O')
                {
                    w_cnt++;
                    dfs_white(i,j);
                }

        for(i=0; i<9; i++)
            for(j=0; j<9; j++)
            {
                if(b_col[i][j] && !w_col[i][j]) b_cnt++;
                if(!b_col[i][j] && w_col[i][j]) w_cnt++;
            }
        printf("Black %d White %d\n",b_cnt,w_cnt);
    }

    return 0;
}
