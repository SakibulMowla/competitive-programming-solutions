#include "bits/stdc++.h"
using namespace std;

#define SZ 16
const int inf = 1<<28;

struct point
{
    int x, y;
};

point dot[SZ+2];
int dp[(1<<SZ)+2];
int line[SZ+2][SZ+2];
int n;

bool same_line(point a,point b,point c)
{
    return (a.y-b.y)*(b.x-c.x) == (a.x-b.x)*(b.y-c.y);
}

int solve(int mask)
{
    int &ret = dp[mask];

    if(ret != -1) return ret;
    if(!mask) return ret = 0;
    if(__builtin_popcount(mask) <= 2) return ret = 1;

    int i, j, k, tmp;
    ret = inf;

    for(i=0;i<n;i++)    if(mask&(1<<i)) break;
    for(j=i+1;j<n;j++)   if(mask&(1<<j))
    {
        tmp = mask & ~line[i][j];
        ret = min(ret, 1+solve(tmp));
    }

    return ret;
}

int main()
{
    int test = 0, t, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0; i<n; i++)
        {
            scanf("%d %d",&dot[i].x, &dot[i].y);
            for(j=i+1; j<n; j++)
                line[i][j] = line[j][i] = 0;
        }

        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++)
            {
                for(k=0; k<n; k++)
                    if(same_line(dot[i], dot[j], dot[k]))
                        line[i][j] |= 1<<k;

                line[j][i] = line[i][j];
            }

        k = 1<<n;

        for(i=0; i<k; i++)
            dp[i] = -1;

        printf("Case %d: %d\n",++test, solve(k-1));
    }

    return 0;
}
