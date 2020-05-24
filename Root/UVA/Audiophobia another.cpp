#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 110
const int inf = 1000000000;

int main()
{
    int test,i,j,k,c,c1,c2,cost,s,q,ans,matrix[SZ][SZ];
    test = 0;
    while(scanf("%d %d %d",&c,&s,&q) == 3)
    {
        if(c==0 && s==0 && q == 0)break;
        for(i=1; i<=c; i++)
            for(j=0; j<=c; j++)
                matrix[i][j] = i==j? 0 : inf;
        for(i=1;i<=s;i++)
        {
            scanf("%d %d %d",&c1,&c2,&cost);
            matrix[c1][c2] = matrix[c2][c1] = cost;
        }
        for(k=1;k<=c;k++)
            for(i=1;i<=c;i++)
                for(j=1;j<=c;j++)
                    matrix[i][j] = min( matrix[i][j] , max(matrix[i][k] , matrix[k][j]) );

        if(test)printf("\n");
        printf("Case #%d\n",++test);
        for(i=1;i<=q;i++)
        {
            scanf("%d %d",&c1,&c2);
            ans = matrix[c1][c2];
            if(ans == inf)
                printf("no path\n");
            else
                printf("%d\n",ans);
        }
    }

    return 0;
}
