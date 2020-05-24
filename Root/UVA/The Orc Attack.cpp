            // 10793 - The Orc Attack
#include <stdio.h>
#include <string.h>
#define SZ 110
#define FOR(a,b) for(a=1;a<=b;a++)
#define max(a,b) a > b ? a : b
#define min(a,b) a < b ? a : b
const int inf = 1000000000;
int matrix[SZ][SZ];
int main()
{
    int i,j,k,flag,ans,t,test,n,e,u,v,c,dist;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d %d",&n,&e);
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
                matrix[i][j] = matrix[j][i] = inf;
            matrix[i][i] = 0;
        }
        for(i=0;i<e;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            if(c < matrix[u][v])
                matrix[u][v] = matrix[v][u] = c;
        }
        FOR(k,n)FOR(i,n)FOR(j,n)matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
        flag = 0;
        ans = -1;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(matrix[i][j] == inf)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        if(flag)
        {
            printf("Map %d: -1\n",t);
            continue;
        }
        for(i=6;i<=n;i++)
        {
            dist = matrix[i][1];
            if(matrix[2][i] == dist && matrix[3][i] == dist && matrix[4][i] == dist && matrix[5][i] == dist)
            {
                dist = 0;
                for(j=1;j<=n;j++)
                    dist = max(dist , matrix[i][j]);
                if(ans == -1)
                    ans = dist;
                else
                    ans = min(ans , dist);
            }
        }
        printf("Map %d: %d\n",t,ans);
    }
    return 0;
}
