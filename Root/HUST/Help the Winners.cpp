#include "stdio.h"
#include "string.h"
#include "iostream"

using namespace std;

typedef long long ll;
#define SZ 15

int mat[SZ+2][SZ+2];
ll dp[(1<<SZ)+2];
ll dp1[(1<<SZ)+2][16];
int n;

ll solve(int indx, int mask)
{
    if(!mask)
        return 1LL;

    ll &ret = dp[mask];
    if(ret != -1)
        return ret;

    int i;
    ret = 0LL;

    for(i=0; i<n; i++)
        if(mask&(1<<i) && mat[indx][i] == 1)
        {
            ret += solve(indx+1, mask&~(1<<i));
        }

    return ret;
}


ll solve1(int indx,int mask,int koyta)
{
//    printf("mask = %d %d\n",mask,koyta);
    if(!mask)
    {
        return (ll)(koyta>0);
//        if(koyta > 0) return 1LL;
//        return 0LL;
    }

    ll &ret = dp1[mask][koyta];
    if(ret != -1)
        return ret;

    int i, f;
    ret = 0LL;

    for(i=0; i<n; i++)
        if(mask&(1<<i))
        {
//            printf("%d %d %d\n",indx,i,mat[indx][i]);
            if(mat[indx][i] == 2) f = 1;
            else f = 0;
            ret += solve1(indx+1, mask&~(1<<i), koyta+f);
        }

    return ret;
}


int main()
{
    int test=0, t, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d",&mat[i][j]);

        k = 1<<n;

        for(i=0; i<k; i++)
        {
            dp[i] = -1;
            for(j=0; j<=n; j++)
                dp1[i][j]= -1;
        }

        printf("Case %d: %lld\n",++test,(ll)(solve(0, k-1)+ solve1(0, k-1, 0)));
    }

    return 0;
}
