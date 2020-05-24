// 10724 - Road Construction
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "iostream"
using namespace std;
struct data{int x,y;};
struct data1{double d,z;int p,q;};
const int inf = 1000000000;
int main()
{
    int n,m,u,v,i,j,k;
    data road[55];
    data1 best;
    double matrix[55][55],dist,predist,sum,w;
    while(scanf("%d %d",&n,&m) == 2 && n && m)
    {
        for(i=1; i<=n; i++)
            scanf("%d %d",&road[i].x,&road[i].y);
        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
                matrix[i][j] = matrix[j][i] = inf;
            matrix[i][i] = 0;
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d %d",&u,&v);
            dist = sqrt( pow(road[u].x - road[v].x , 2) + pow(road[u].y - road[v].y , 2) );
            matrix[u][v] = matrix[v][u] = dist;
        }
        for(k=1; k<=n; k++)
            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                    matrix[i][j] = min( matrix[i][j] , matrix[i][k] + matrix[k][j] );
        best.d = 0;
        for(u=1; u<=n; u++)
        {
            for(v=u+1; v<=n; v++)
            {
                sum = 0;
                w = sqrt( pow(road[u].x - road[v].x , 2) + pow(road[u].y - road[v].y , 2) );
                for(i=1; i<=n; i++)
                {
                    for(j=i+1; j<=n; j++)
                    {
                        predist = matrix[i][j];
                        dist = min( matrix[i][j] , min( matrix[i][u]+w+matrix[v][j] , matrix[i][v]+w+matrix[u][j] ) );
                        sum += (predist - dist);
                    }
                }
                if(sum > 1.0)
                {
                    if(sum > best.d || (sum == best.d && w < best.z))
                    {
                        best.d = sum;
                        best.z = w;
                        best.p = u;
                        best.q = v;
                    }
                }
            }
        }
        if(best.d == 0)
            printf("No road required\n");
        else
            printf("%d %d\n",best.p,best.q);
    }

    return 0;
}
