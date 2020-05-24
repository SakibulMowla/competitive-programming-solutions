#include "stdio.h"
#define SZ 110
#define FOR(a,b,c) for(a=c;a<=b;a++)

int dest[SZ] , matrix[SZ][SZ];

void init(int n)
{
    int i,j;
    FOR(i,n,0)
    {
        FOR(j,n,i+1)
            matrix[i][j] = matrix[j][i] = 0;
        matrix[i][i] = 1;
    }
}

void floyd_warshall(int n)
{
    int i,j,k;
    FOR(k,n,1) FOR(i,n,1) FOR(j,n,1)
        matrix[i][j] = ( (matrix[i][j] == 1) || (matrix[i][k] + matrix[k][j] == 2) );
}

int main()
{
    int i,j,k,n;
    while(scanf("%d",&n) == 1)
    {
        init(n);
        FOR(i,n,1)
            scanf("%d",&dest[i]);
        FOR(i,n,1)
        {
            scanf("%d",&j);
//            printf("i = %d j = %d\n",i,j);
            if(i+j <= n) matrix[i][i+j] = matrix[i+j][i] = 1;
            if(i-j >= 1) matrix[i][i-j] = matrix[i-j][i] = 1;
        }
        floyd_warshall(n);
        k = 0;
        FOR(i,n,1)
        {
            if(matrix[i][dest[i]] == 0)
            {
                k = 1;
//                printf("i = %d dest = %d k = %d\n",i,dest[i],k);
                break;
            }
        }
        if(k) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}
