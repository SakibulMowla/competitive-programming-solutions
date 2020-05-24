#include "stdio.h"
#define SZ 110

int mat[SZ][SZ], ind[SZ], vis[SZ];

void init(int n)
{
    int i, j;
    for(i=0; i<=n; i++)
    {
        vis[i] = 0;
        ind[i] = 0;
        for(j=0; j<=n; j++)
            mat[i][j]= 0;
    }
}

int main()
{
    int i, j, k, n, m, blank;

    while(scanf("%d %d",&n,&m) == 2)
    {
        init(n);

        while(m--)
        {
            scanf("%d %d",&j,&i);
            while(i--)
            {
                scanf("%d",&k);
                mat[k][j] = 1;
                ind[j]++;
            }
        }

        blank = 0;

        for(k=1; k<=n; k++)
            for(i=1; i<=n; i++)
            {
                if(!ind[i] && !vis[i])
                {
                    vis[i] = 1;
                    if(blank) printf(" ");
                    else blank = 1;
                    printf("%d",i);

                    for(j=1; j<=n; j++)
                        if(mat[i][j] && vis[j] == 0)
                            ind[j]--;
                    break;
                }
            }
        printf("\n");
    }

    return 0;
}
