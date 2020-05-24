#include "bits/stdc++.h"
using namespace std;

#define SZ 22

char arr[SZ][SZ];
int tot;

struct point
{
    int x, y;
};
point nut[SZ];

int dp[SZ][(1<<17)+2];

int dist(int a,int b)
{
    return max(abs(nut[a].x-nut[b].x), abs(nut[a].y-nut[b].y));
}

int solve(int pos, int mask)
{
    if(!mask) return dist(pos, 0);
    int &ret = dp[pos][mask];

    if(ret != -1)   return ret;
    ret = 1<<28;

    int i;

    for(i=0;i<tot;i++)
        if((mask&(1<<i)) && i != pos)
            ret = min(ret, dist(i, pos) + solve(i, mask&~(1<<i)));

    return ret;
}


int main()
{
    int n, m, i, j, k;

    while(~scanf("%d %d",&n,&m))
    {
        tot = 1;

        for(i=0;i<n;i++)
        {
            scanf("%s",arr[i]);
            for(j=0;j<m;j++)
            {
                if(arr[i][j] == 'L')
                    nut[0].x = i, nut[0].y = j;
                else if(arr[i][j] == '#')
                    nut[tot].x = i, nut[tot++].y = j;
            }
        }

        k = 1<<tot;

        for(j=0;j<tot;j++)
            for(i=0;i<=k;i++)
                dp[j][i] = -1;

        printf("%d\n",solve(0, k-2));
    }

    return 0;
}
