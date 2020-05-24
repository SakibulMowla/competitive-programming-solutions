#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

#define inf 1<<28
#define SD(n) scanf("%d",&n)
#define SS(n) scanf("%s",n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 1010

int matrix[210][210];

int main()
{
    int i,j,k,n,m,l,node,node1,node2,dist,maxdist,no;
    while(scanf("%d %d",&n,&m) == 2)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                matrix[i][j] = 1<<28;
            matrix[i][i] = 0;
        }

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            matrix[j][k] = matrix[k][j] = l;
        }

        if(m == 1)
        {
            printf("%lf\n",(double)matrix[1][2]/2);
            continue;
        }

        for(k=1; k<=n; k++)
            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                    matrix[i][j] = min( matrix[i][j] , matrix[i][k] + matrix[k][j] );

        maxdist  = 1<<28;
        for(i=1;i<=n;i++)
        {
            dist = -1;
            for(j=1;j<=n;j++)
            {
                if(j == i) continue;
                if(matrix[i][j] > dist) dist = matrix[i][j] , no = j;
            }
            if(dist < maxdist) maxdist = dist , node = i , node1 = no;
        }

        maxdist = -1;
        for(i=1;i<=n;i++)
        {
            if(i == node || i == node1 ) continue;
            if(matrix[node][i] > maxdist) maxdist = matrix[node][i] , node2 = i;
        }

        k = matrix[node][node1] + matrix[node][node2];

        printf("%lf\n",(double)k/2);
    }

    return 0;
}
