#include <stdio.h>
#include <iostream>

using namespace std;

#define SZ 105
#define FOR(a,val,b) for(a=val;a<=b;a++)
int matrix[SZ][SZ];
const int inf = 1<<28;

void init(int n)
{
    int i,j;
    FOR(i,1,n)
    {
        FOR(j,i+1,n)
            matrix[i][j] = matrix[j][i] = inf;
        matrix[i][i] = 0;
    }
}

int main()
{
    int n,m,t,test,u,v,w,i,j,k;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        init(n);
        FOR(i,1,m)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(matrix[u][v] > w) matrix[u][v] = matrix[v][u] = w;
        }
        FOR(k,1,n)FOR(i,1,n)FOR(j,1,n) matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
        if(matrix[1][n] >= inf) printf("Case %d: Impossible\n",++t);
        else printf("Case %d: %d\n",++t,matrix[1][n]);
    }

    return 0;
}
