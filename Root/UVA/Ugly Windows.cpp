#include "stdio.h"
#include "string.h"
#include "stdbool.h"

#define SZ 110

char arr[SZ][SZ];
bool mark[200] , dir[5] , color[SZ][SZ];

int main()
{
    freopen("1.txt","r",stdin);
    int i,j,k,n,m,row,col,flag,before,p,q,r,s;
    while(scanf("%d %d",&row,&col) == 2 && (row+col))
    {

        for(i=0; i<row; i++) scanf("%s",arr[i]);
        for(i=0; i<row; i++) for(j=0; j<col; j++)
                if(arr[i][j]>='A' && arr[i][j]<='Z' && mark[ arr[i][j] ] == 0 && color[i][j] == 0)
                {
                    memset(dir,0,sizeof(dir));
                    n = i , m = j;
                    flag = 0;
                    before = -1;
                    for(k=0; k<4; k++)
                    {
                        if(m+1<col&&arr[n][m+1]==arr[i][j]&&!dir[0] && before != 1)
                        {
                            before = 0;
                            flag=1;
                            dir[0]=1;
                            color[n][m] = 1;
                            while(m+1<col && arr[n][m+1]==arr[i][j]) m++ , color[n][m] = 1;
                            s = m;
                        }
                        else if(m-1>=0&&arr[n][m-1]==arr[i][j]&&!dir[1] && before != 0)
                        {
                            before = 1;
                            flag=1;
                            dir[1]=1;
                            color[n][m] = 1;
                            while(m-1>=0 && arr[n][m-1]==arr[i][j]) m-- , color[n][m] = 1;
                        }
                        else if(n+1<row&&arr[n+1][m]==arr[i][j]&&!dir[2] && before != 3)
                        {
                            before = 2;
                            flag=1;
                            dir[2]=1;
                            color[n][m] = 1;
                            while(n+1<row && arr[n+1][m]==arr[i][j]) n++ , color[n][m] = 1;
                            r = n;
                        }
                        else if(n-1>=0&&arr[n-1][m]==arr[i][j]&&!dir[3] && before != 2)
                        {
                            before = 3;
                            flag=1;
                            dir[3]=1;
                            color[n][m] = 1;
                            while(n-1>=0 && arr[n-1][m]==arr[i][j]) n-- , color[n][m] = 1;
                        }
                    }
                    if(n==i && m==j && flag == 1)
                    {
                        flag = 0;
                        for(p=i+1; p<r; p++) for(q=j+1; q<s; q++) if(arr[p][q] != '.'){flag = 1;break;}
                        if(flag == 0) mark[ arr[i][j] ] = 1;
                    }
                }
        for(i='A'; i<='Z'; i++) if(mark[i]) printf("%c",i);
        printf("\n");
        memset(mark,0,sizeof(mark));
        for(i=0;i<row;i++) for(j=0;j<col;j++) color[i][j] = 0;
    }

    return 0;
}
