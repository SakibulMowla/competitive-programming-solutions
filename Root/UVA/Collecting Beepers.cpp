#include "bits/stdc++.h"
using namespace std;

#define SZ 12
const int inf = 1e9;

struct data
{
    int x, y;
};
data point[SZ];

int dp[SZ][1<<SZ];
int n;

int solve(int pos, int mask)
{
    int &ret = dp[pos][mask];

    if(ret != -1) return ret;
    if(!mask)     return ret = abs(point[pos].x-point[0].x) + abs(point[pos].y-point[0].y);

    int i, tmp;
    ret = inf;

    for(i=1; i<n; i++)
    {
        if(mask&(1<<i))
            ret = min(ret, solve(i, mask&~(1<<i)) + abs(point[pos].x-point[i].x) + abs(point[pos].y-point[i].y));
    }

    return ret;
}

int main()
{
    int t, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%*d %*d");
        scanf("%d %d",&point[0].x,&point[0].y);

        scanf("%d",&n);

        for(i=1; i<=n; i++)
        {
            scanf("%d %d",&point[i].x,&point[i].y);
        }

        n++;
        k = (1<<n) - 1;

        for(i=0;i<=n;i++)
            for(j=0;j<=k;j++)
                dp[i][j] = -1;


        printf("The shortest path has length %d\n",solve(0, k-1));
    }

    return 0;
}
