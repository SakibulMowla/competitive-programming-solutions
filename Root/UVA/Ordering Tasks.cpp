#include <stdio.h>
#include <string.h>

int mat[110][110];
int work[110];

int main()
{
    int n,m,i,j,k,l,p,q,nodes;
    int ans[110];
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n==0 && m==0)break;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                mat[i][j] = mat[j][i] = 0;
        for(i=1;i<=n;i++)
            work[i] = 0;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&p,&q);
            mat[p][q] = 1;
            work[q]++;
        }
        nodes=1;
        while(nodes<=n)
        {
            for(i=1;i<=n  &&  nodes<=n;i++)
            {
                if(work[i]==0)
                {
                    ans[nodes++]=i;
                    work[i] = -1;
                    for(j=1;j<=n;j++)
                    {
                        if(mat[i][j] == 1)
                            work[j]--;
                    }
                }
            }
        }
        printf("%d",ans[1]);
        for(i=2;i<=n;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }

    return 0;
}
