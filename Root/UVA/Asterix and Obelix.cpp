// 10246 - Asterix and Obelix
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "iostream"
using namespace std;
#define FOR(a,b) for(a=1;a<=b;a++)
const int inf = 1000000000;
int main()
{
    int test,c,r,q,i,j,k,dist,party,feast[85],cost[85][85],matrix[85][85];
    test = 0;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d %d",&c,&r,&q) == 3 && c && r && q )
    {
        FOR(i,c)
        scanf("%d",&feast[i]);
        FOR(i,c)
        {
            FOR(j,c)
                matrix[i][j] = inf;
            matrix[i][i] = 0;
        }
        FOR(i,c)for(j=i+1;j<=c;j++)cost[i][j] = cost[j][i] = max(feast[i] , feast[j]);
        FOR(i,r)
        {
            scanf("%d %d %d",&j,&k,&dist);
            matrix[j][k] = matrix[k][j] = dist;
        }
        FOR(k,c)FOR(i,c)FOR(j,c)
        {
            dist = matrix[i][k] + matrix[k][j];
            party = max(cost[i][k] , cost[k][j]);
            if(dist + party < matrix[i][j] + cost[i][j])
            {
                matrix[i][j] = dist;
                cost[i][j] = party;
            }
        }
        FOR(k,c)FOR(i,c)FOR(j,c)
        {
            dist = matrix[i][k] + matrix[k][j];
            party = max(cost[i][k] , cost[k][j]);
            if(dist + party < matrix[i][j] + cost[i][j])
            {
                matrix[i][j] = dist;
                cost[i][j] = party;
            }
        }
        if(test)printf("\n");
        printf("Case #%d\n",++test);
        FOR(i,q)
        {
            scanf("%d %d",&j,&k);
            if(matrix[j][k] == inf)
                printf("-1\n");
            else
                printf("%d\n",matrix[j][k]+cost[j][k]);
        }
    }

    return 0;
}
