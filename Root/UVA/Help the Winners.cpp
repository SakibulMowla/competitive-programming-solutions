#include "bits/stdc++.h"
using namespace std;

#define SZ 15
typedef long long ll;

ll dp[(1<<SZ)+2][2][2]; // mask , all_one, atleast one two
int mat[SZ+2][SZ+2];
int n;

ll solve(int indx, int mask, bool one, bool two)
{
    if(!mask)
        return (ll)(one or two);

    ll &ret = dp[mask][one][two];
    if(ret != -1)
        return ret;

    int i;
    ret = 0LL;

    for(i=0;i<n;i++)
        if(mask&(1<<i))
            ret += solve(indx+1, mask&~(1<<i), one and (mat[indx][i]==1), two or (mat[indx][i] == 2));

    return ret;
}


int main()
{
    int test=0, t, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&mat[i][j]);

        k = 1<<n;

        for(i=0;i<k;i++)
            dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;

        printf("Case %d: %lld\n",++test,solve(0, k-1, true, false));
    }

    return 0;
}
