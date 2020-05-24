#include "stdio.h"
#include "iostream"
using namespace std;

#define SZ 102
#define SZ1 1002

typedef long long ll;
const int inf = 1e9;

int dp[SZ][SZ][SZ1];
int w[SZ], v[SZ];
int N, M, L;

int solve(int n, int m, int len)
{
//    printf("N = %d\n",N);
    if(m == M)
        return 0LL;
    if(n == N)
        return -inf;

    int &ret = dp[n][m][len];
    if(ret != -1) return ret;

    ret = -inf;

    ret = max(ret, solve(n+1, m, len));
    if(len + w[n] <= L) ret = max(ret, v[n] + solve(n+1, m+1, len+w[n]));

    return ret;
}

int main()
{
//    printf("%d %d\n",sizeof(int),sizeof(ll));
//    freopen("2.txt","r",stdin);
    int t, i, j, k;
//    long long ans;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d",&N,&M,&L);

        for(i=0; i<N; i++)
            scanf("%d %d",&w[i],&v[i]);

        for(i=0; i<=N; i++)
            for(j=0; j<=N; j++)
                for(k=0; k<=L; k++)
                    dp[i][j][k] = -1;

        k = solve(0, 0, 0);

        if(k < 0) k = 0;

        printf("%d\n",k);
    }

    return 0;
}

/*
1
2 1 3
2 3
3 4

*/
