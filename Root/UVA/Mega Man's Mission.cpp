#include "bits/stdc++.h"
using namespace std;

#define SZ 16
typedef long long ll;

ll dp[(1<<SZ)+2];
int mat[SZ+2][SZ+2];
int mine[SZ+2];
int n;

ll solve(int mask)
{
    if(!mask)
        return 1LL;

    ll &ret = dp[mask];
    if(ret != -1)
        return ret;

    int i, j;
    ret = 0LL;

    bool col[SZ+2];
    memset(col, 0, sizeof(col));

    for(i=0; i<n; i++)
        if((mask&(1<<i)) && mine[i] == 1)
        {
            col[i] = 1;
            ret += solve(mask&~(1<<i));
        }

    for(i=0; i<n; i++)
        if((mask&(1<<i)) == 0)
        {
            for(j=0; j<n; j++)
                if((mask&(1<<j)) && col[j] == 0 && mat[i][j] == 1)//
                {
                    col[j] = 1;
                    ret += solve(mask&~(1<<j));
                }
        }

    return ret;
}

int main()
{
    int test=0, t, i, j, k;
    char arr[100];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        scanf("%s",arr);

        for(j=0; arr[j]; j++)
            mine[j] = arr[j]-'0';

        for(i=0; i<n; i++)
        {
            scanf("%s",arr);
            for(j=0; arr[j]; j++)
                mat[i][j] = arr[j]-'0';
        }

        k = 1<<n;

        for(i=0; i<k; i++)
            dp[i] = -1;

        printf("Case %d: %lld\n",++test,solve(k-1));
    }

    return 0;
}

