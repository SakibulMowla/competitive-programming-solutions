#include "stdio.h"
#define SZ 15

struct data
{
    int x,y;
};

data mat[SZ];
int m[SZ][SZ];
int s[SZ][SZ];

void print(int i,int j)
{
    if(i == j)
        printf("A%d",i);
    else
    {
        printf("(");
        print(i, s[i][j]);
        printf(" x ");
        print(s[i][j]+1, j);
        printf(")");
    }
}

int main()
{
    int test=0, n, q, i, j, k, l;

    while(scanf("%d",&n) == 1 && n)
    {
        for(i=1; i<=n; i++)
            scanf("%d %d",&mat[i].x, &mat[i].y);
        for(i=1;i<=n;i++)
            m[i][i] = 0;
        for(l=2;l<=n;l++)
        {
            for(i=1;i<=n-l+1;i++)
            {
                j = i + l - 1;
                m[i][j] = 1<<28;
                for(k=i;k<=j-1;k++)
                {
                    q = m[i][k] + m[k+1][j] + ( mat[i].x * mat[k].y * mat[j].y );
                    if(q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
//        printf("cost = %d\n",m[1][n]);
        printf("Case %d: ",++test);
        print(1, n);
        printf("\n");
    }

    return 0;
}

