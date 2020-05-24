#include "stdio.h"
#include "iostream"

using namespace std;

#define SZ 110

const int inf = 1e9;

int mat[SZ][SZ];
int cyc[SZ][SZ];

int main()
{
    int i, j, k, l, n, m, ans;

    while(~scanf("%d %d",&n,&m))
    {
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=n; j++)
                mat[i][j] = inf;
//            mat[i][i] = 0;
        }

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            if(mat[j][k] > l)
                mat[j][k] = mat[k][j] = l;
        }

        ans = inf;

        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                cyc[i][j] = mat[i][j];

        for(k=1; k<=n; k++)
        {
            for(i=1; i<k; i++)
                for(j=1; j<i; j++)
                    ans = min(ans, mat[i][j] + cyc[j][k] + cyc[k][i]);

            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        }

        if(ans >= inf) printf("It's impossible.\n");
        else           printf("%d\n",ans);
    }

    return 0;
}
