#include "bits/stdc++.h"
using namespace std;

#define SZ 15
#define SZ1 110
#define SZ2 32768

int Switch[110];
int dp[SZ2];
queue <int> Q;

int bfs(int mask, int m)
{
    while(!Q.empty()) Q.pop();

    int i, j;

    dp[mask] = 0;
    Q.push(mask);

    while(!Q.empty())
    {
        mask = Q.front();
        Q.pop();
        if(mask == 0) return dp[mask];

        for(i=0;i<m;i++)
        {
            j = mask ^ Switch[i];
            if(dp[j] == -1)
            {
                dp[j] = dp[mask] + 1;
                Q.push(j);
            }
        }
    }

    return -1;
}


int main()
{
    int test=0, t, i, j, k, n, m;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(i=0;i<m;i++)
        {
            Switch[i] = 0;
            for(j=0;j<n;j++)
            {
                scanf("%d",&k);
                Switch[i] <<= 1;
                Switch[i] |= k;
            }
        }

        k = 1<<n;

        for(i=0;i<k;i++)
            dp[i] = -1;

        printf("Case %d: ",++test);

        k = bfs(k-1, m);

        if(k == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n",k);
    }

    return 0;
}
