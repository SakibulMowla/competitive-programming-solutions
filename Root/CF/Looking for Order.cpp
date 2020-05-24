#include "bits/stdc++.h"
using namespace std;

#define SZ 24
const int inf = 1<<28;

int x[SZ+2], y[SZ+2];
int dist[SZ+2][SZ+2];
int dp[(1<<SZ)+2];
int nxt[(1<<SZ)+2];
int n;

int sqr_dis(int a,int b)
{
    return (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
}

int solve(int mask)
{
//    printf("mask = %d\n",mask);
    if(!mask) return 0;

    int &ret = dp[mask];
    if(ret != -1)   return ret;

    int i, j, k;
    ret = inf;

    for(i=0; i<n; i++)
        if(mask&(1<<i))
        {
            for(j=0; j<n; j++)
                if(mask&(1<<j))
                {
//                    printf("i = %d j = %d dist = %d\n",i,j,dist[i+1][j+1]);
                    k = dist[0][i+1] + dist[i+1][j+1] + dist[j+1][0] + solve((mask&~(1<<i))&~(1<<j));
                    if(k < ret)
                    {
                        ret = k;
//                        printf("mask %d %d %d\n",mask,i,j);
                        nxt[mask] = (1<<i)|(1<<j);
                    }
                }

            break;
        }

    return ret;
}


int main()
{
    int i, j, k;

    scanf("%d %d %d",&x[0],&y[0],&n);

    for(i=1; i<=n; i++)
        scanf("%d %d",&x[i],&y[i]);

    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            dist[i][j] = dist[j][i] = sqr_dis(i, j);

//    for(i=0;i<=n;i++)
//        for(j=0;j<=n;j++)
//            printf("i j dist %d %d %d\n",i,j,dist[i][j]);

    k = 1<<n;

    for(i=0; i<k; i++)
        dp[i] = -1;

    printf("%d\n",solve(k-1));

    printf("0");

    k--;

//    printf("\nnxt = %d\n",nxt[3]);

    while(k)
    {
        for(i=0; i<n; i++)
            if(nxt[k]&(1<<i))
                printf(" %d",i+1);
        printf(" 0");
        k ^= nxt[k];
    }

    printf("\n");

    return 0;
}
