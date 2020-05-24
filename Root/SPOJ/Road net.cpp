#include "stdio.h"
#include "string.h"
#include "math.h"

#define SZ 210

int matrix[SZ][SZ] ,ans[SZ][SZ];

int main()
{
    int i,j,k,n,t,test;
    t=0;
    scanf("%d",&test);
    while(test--)
    {
        if(t)printf("\n");
        t++;
        scanf("%d",&n);
        for(i=1; i<=n; i++) for(j=1; j<=n; j++) ans[i][j] = 0 , scanf("%d",&matrix[i][j]);
        for(k=1; k<=n; k++) for(i=1; i<=n; i++) for(j=1; j<=n; j++)
        {
            if(i!=k && j!=k && matrix[i][j] == matrix[i][k] + matrix[k][j]) ans[i][j] = -1;
        }
        for(i=1; i<=n; i++) for(j=i+1; j<=n; j++) if(ans[i][j] != -1) printf("%d %d\n",i,j);
    }

    return 0;
}
