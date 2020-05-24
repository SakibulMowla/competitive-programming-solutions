#include "stdio.h"
#include "math.h"
#include "iostream"

using namespace std;

#define SZ (1<<20)+2
#define SZ1 22

double dp[SZ];
int n;
struct data
{
    int x, y;
};

data mine, point[SZ1];

double solve(int mask)
{
    if(!mask) return 0.0;

    double &ret = dp[mask];
    if(ret != -1.0) return ret;

    int i, j, tmp;
    double dist, dist1;
    ret = 1e10;

    for(i=0; i<n; i++) if( mask&(1<<i) ) break;

    for(j=i+1; j<n; j++) if( mask&(1<<j) )
    {
        dist = sqrt( pow(mine.x-point[i].x, 2) + pow(mine.y-point[i].y, 2) );
        dist += sqrt( pow(point[i].x-point[j].x, 2) + pow(point[i].y-point[j].y, 2) );
        dist1 = sqrt( pow(mine.x-point[j].x, 2) + pow(mine.y-point[j].y, 2) );
        dist1 += sqrt( pow(point[j].x-point[i].x, 2) + pow(point[j].y-point[i].y, 2) );

        dist = min(dist, dist1);

//      printf("i = %d j = %d dist = %lf\n",i,j,dist);

        tmp = mask&~(1<<i);
        tmp = tmp&~(1<<j);

        ret = min(ret, dist+solve(tmp));
    }

    return ret;
}

int main()
{
//    freopen("2.txt","r",stdin);
    int test = 0, t, i, lim;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&mine.x,&mine.y);
        scanf("%d",&n);
        n <<= 1;
        lim = (1<<n) - 1;
        for(i=0; i<=lim; i++)
            dp[i] = -1.0;
        for(i=0; i<n; i++)
            scanf("%d %d",&point[i].x,&point[i].y);
        printf("Case #%d: %.2lf\n",++test, solve(lim));
    }

    return 0;
}
