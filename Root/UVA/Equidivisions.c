#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int square ,arr[110][110],cnt , color[110][110];

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

void equadivision(int n,int m)
{
    color[n][m] = 1;
    cnt++;
    int i,u,v;
    for(i=0;i<4;i++)
    {
        u = n + x[i];
        v = m + y[i];
        if(u>=1 && v>=1 && u<=square && v<=square && color[u][v] == 0 && arr[n][m] == arr[u][v])
        {
            equadivision(u,v);
        }
    }
}

int main()
{
    int n,i,j,a,b,flag,ans,taken[110];
    char tmp[1010];
    while(scanf("%d",&n) == 1 && n)
    {
        square = n;
        memset(arr,0,sizeof(arr));
        memset(color,0,sizeof(color));
        memset(taken,0,sizeof(taken));
        for(i=1; i<n; i++)
        {
            scanf(" %[^\n]",tmp);
            a = b = 0;
            for(j=0;j<strlen(tmp);j++)
            {
                while(tmp[j] != ' ' && j<strlen(tmp))
                {
                    a = (a * 10) + tmp[j] - '0';
                    j++;
                }
                j++;
                while(tmp[j] != ' ' && j<strlen(tmp))
                {
                    b = (b * 10) + tmp[j] - '0';
                    j++;
                }
                arr[a][b] = i;
                a = b = 0;
            }
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(arr[i][j] == 0)
                    arr[i][j] = n;
        flag = 0;
        cnt = 0;
        equadivision(1,1);
        taken[arr[1][1]] = 1;
        ans = cnt;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(color[i][j] == 0)
                {
                    if(taken[arr[i][j]] == 1)
                    {
                        flag = 1;
                        break;
                    }
                    cnt = 0;
                    equadivision(i,j);
                    if(cnt != ans)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 1) break;
        }
        if(flag == 1) printf("wrong\n");
        else printf("good\n");
    }

    return 0;
}
