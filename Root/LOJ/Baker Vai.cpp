#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<ll,ll> pii;

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 110
const ll inf = 1LL<<28;
const ll mod = 1LL;

int dp[SZ][SZ][SZ][3], grid[SZ][SZ];
int n, m;

int solve(int row, int col1, int col2, int nextmove)
{
    if(row == n-1 and col1 == m-2 and col2 == m-1 && nextmove == 0)
        return 0;

    int &ret = dp[row][col1][col2][nextmove];
    if(ret != -1)
        return ret;

//    if(col1 == col2)
//        printf("%d %d %d\n",row,col1,col2);

//    printf("yes\n");

    ret = 0;

    if(nextmove == 0)
    {
        if(col1+1 < col2)
            ret = solve(row, col1+1, col2, 0) + grid[row][col1+1];
        ret = max(ret, solve(row, col1, col2, 1));
    }

    else if(nextmove == 1)
    {
        if(col2+1 < m)
            ret = solve(row, col1, col2+1, 1) + grid[row][col2+1];
        if(col1 < col2)
            ret = max(ret, solve(row, col1, col2, 2));
    }

    else
    {
        if(row+1 < n)
            ret = solve(row+1, col1, col2, 0) + grid[row+1][col1] + grid[row+1][col2];
    }

    return ret;
}


int main()
{
    int test=0, t, i, j, j1, k;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                scanf("%d",&grid[i][j]);

        for(i=0; i<=n; i++)
            for(j=0; j<=m; j++)
                for(j1=0; j1<=m; j1++)
                    for(k=0; k<=2; k++)
                        dp[i][j][j1][k] = -1;

        printf("Case %d: %d\n",++test, solve(0, 0, 0, 1) + grid[0][0]);
    }

    return 0;
}
