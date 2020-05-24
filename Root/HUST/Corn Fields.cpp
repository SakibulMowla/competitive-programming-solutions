#include "iostream"
#include "stdio.h"
#include "string.h"

#define SZ 12

typedef long long ll;

const ll mod = 100000000LL;

ll dp[SZ+2][(1<<SZ)+2];
int mat[SZ+2][SZ+2];
int mark[SZ+2];
int n, m;

//void print(int p)
//{
//    int i;
//    for(i=5;i>=0;i--)
//        printf("%d",(p&(1<<i)) > 0 );
//    printf("\n");
//}

bool valid(int pre_mask, int now_mask)
{
//    printf("printing Mask\n");
//    print(pre_mask);
//    printf("\n");
//    print(now_mask);
//    printf("\n");

    int i;

    for(i=0;i<12;i++)
        if((pre_mask&(1<<i)) && (now_mask&(1<<i)))
            return false;

    int pre = 0, now;

    for(i=0;i<12;i++)
    {
        now = (now_mask&(1<<i)) > 0;
        if(now == 1 && pre == 1)
            return false;
        pre = now;
    }


//    printf("VVVVVAAAAALLLLLLLIIIIDDDDDDDDD\n");

    return true;
}

ll solve(int row, int pre_mask)
{
    if(row == n) return 1LL;

    ll &ret = dp[row][pre_mask];
    if(ret != -1) return ret;

    int i;
    ret = 0LL;

    for(i=mark[row]; i>=0;)
    {
        if(valid(pre_mask, i))
            ret = (ret + solve(row+1, i)) % mod;
        i--;
        if(i >= 0)
            i &= mark[row];
    }

    return ret;
}

int main()
{
    int i, j;
    scanf("%d %d",&n,&m);

    memset(dp, -1, sizeof(dp));

    for(i=0; i<n; i++)
    {
        mark[i]= 0;
        for(j=0; j<m; j++)
        {
//            printf("ij = %d %d\n",i,j);
            scanf("%d",&mat[i][j]);
            mark[i] <<= 1;
            mark[i] |= mat[i][j];
        }
    }

    printf("%lld\n",solve(0, 0));

    return 0;
}
