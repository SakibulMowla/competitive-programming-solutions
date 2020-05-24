#include <stdio.h>

#define FOR(a,b) for(a=0;a<b;a++)
#define max(a,b) a>b ? a : b
#define min(a,b) a<b ? a : b

int n, matrix[110][110];
const int inf = 1000000000;

void floyd_warshall(void)
{
    int i,j,k;
    FOR(k,n)FOR(i,n)FOR(j,n){matrix[i][j] = min( matrix[i][j] , matrix[i][k] + matrix[k][j] );}
}

int main()
{
    int t,test,r,u,v,i,j,ans,s,d;

    scanf("%d",&test);
    FOR(t,test)
    {
        scanf("%d",&n);
        scanf("%d",&r);

        FOR(i,n)FOR(j,n){matrix[i][j] = matrix[j][i] = i==j ? 0 : inf;}

        FOR(i,r)
        {
            scanf("%d %d",&u,&v);
            matrix[u][v] = matrix[v][u] = 1;
        }
        scanf("%d %d",&s,&d);
        floyd_warshall();
        ans = -1;
        FOR(i,n)
        {
            ans = max(ans , matrix[s][i] + matrix[i][d]);
        }
        printf("Case %d: %d\n",t+1,ans);
    }

    return 0;
}
