#include "stdio.h"
#include "string.h"

#define SZ 15

char grid[SZ][SZ];
int n , M[30];
int x[] = {0,0,-1,1};
int y[] = {-1,1,0,0};

void fill(int p,int m)
{
    int i,j,k;
    memset(M,0,sizeof(M));
    for(i=0;i<4;i++)
    {
        j = p + x[i];
        k = m + y[i];
        if(j >=0 && k >= 0 && j < n && k < n && grid[j][k] >= 'A' && grid[j][k] <= 'Z')
            M[grid[j][k]-'A'] = 1;
    }
    for(i='A';i<='Z';i++)
        if(M[i-'A'] == 0)
        {
            grid[p][m] = (char)i;
            return;
        }
}

int main()
{
    int t,i,j,test=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%s",grid[i]);
        for(i=0;i<n;i++)
            for(j=0;j<=n;j++)
                if(grid[i][j] == '.')
                    fill(i,j);
        printf("Case %d:\n",++test);
        for(i=0;i<n;i++)
            printf("%s\n",grid[i]);
    }

    return 0;
}
