#include "bits/stdc++.h"
using namespace std;

#define SZ 110
#define SZ1 1030

typedef long long ll;

bool check(int num, int mask)
{
    while(num)
    {
        if( mask & (1<<(num%10)) ) return false;
        num /= 10;
    }
    return true;
}

int Set(int num, int mask)
{
    while(num)
    {
        mask = mask | (1<<(num%10));
        num /= 10;
    }
    return mask;
}

int arr[SZ];
ll dp[SZ][SZ1];
int cnt[SZ][SZ1];
char col[SZ][SZ1];
int N;

bool yes(int a, int b, int c, int d, int e, int f)
{
    if((dp[a][b] + e > dp[c][d]) || (dp[a][b] + e == dp[c][d] && cnt[a][b] + f > cnt[c][d]))
        return true;
    return false;
}

void solve(int indx, int mask)
{
    if(indx == N || col[indx][mask])
        return;

    col[indx][mask] = 1;

    solve(indx+1, mask);

    if(yes(indx+1, mask, indx, mask, 0, 0))
    {
        dp[indx][mask] = dp[indx+1][mask];
        cnt[indx][mask] = cnt[indx+1][mask];
    }

    if(check(arr[indx], mask))
    {
        int tmp = Set(arr[indx], mask);

        solve(indx+1, tmp);

        if(yes(indx+1, tmp, indx, mask, arr[indx], 1))
        {
            dp[indx][mask] = dp[indx+1][tmp] + arr[indx];
            cnt[indx][mask] = cnt[indx+1][tmp] + 1;
        }
    }

    return ;
}

int main()
{
    int i, j;

    while(scanf("%d",&N) == 1)
    {
        for(i=0; i<N; i++)
            scanf("%d",&arr[i]);

        for(i=0; i<=N; i++)
            for(j=0; j<=1024; j++)
            {
                dp[i][j] = 0;
                cnt[i][j] = 0;
                col[i][j] = 0;
            }

        solve(0, 0);

        printf("%d\n",cnt[0][0]);
    }

    return 0;
}
