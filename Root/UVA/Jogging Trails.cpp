/*The number of vertices of odd degree must be even.*/

#include "stdio.h"
#include "iostream"

using namespace std;

int dist[16][16];
int deg[16];
int dp[(1<<15)+2];
int n;

int solve(int mask)
{
    if(!mask) return 0;
    int &ret = dp[mask];
    if(ret != -1) return ret;

    int i, j;
    ret = 1<<28;

    for(i=0; i<n; i++)
        if(mask&(1<<i))
            break;
    for(j=i+1; j<n; j++)
        if(mask & (1<<j))
        {
            ret = min(ret, dist[i][j] + solve(mask&~(1<<i)&~(1<<j)));
        }

    return ret;
}

int main()
{
    int m, i, j, k, l, sum, mask;

    while(scanf("%d",&n) == 1 && n)
    {
        scanf("%d",&m);

        sum = 0;

        for(i=0; i<=n; i++)
        {
            deg[i] = 0;
            for(j=0; j<=n; j++)
                dist[i][j] = 1<<28;
            dist[i][i] = 0;
        }

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            --j,--k;
            deg[j]++;
            deg[k]++;
            dist[j][k] = dist[k][j] = min(dist[j][k], l);
            sum += l;
        }

        for(k=0; k<n; k++)
            for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        mask = 0;

        for(i=0; i<n; i++)
            if(deg[i] % 2)
                mask |= 1<<i;
        k = 1<<n;

        for(i=0; i<=k; i++)
            dp[i] = -1;

        printf("%d\n",sum+solve(mask));
    }

    return 0;
}
