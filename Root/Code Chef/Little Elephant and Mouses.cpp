using namespace std;

#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

#define SZ 110
#define MP(a,b) make_pair(a,b)
#define X first
#define Y second

typedef pair<int , int> pii;

const int inf = 1<<28;
int dp[SZ][SZ][2][2], r, c;
char arr[SZ][SZ];
bool col[SZ][SZ];

int x[] = {0,1,0,-1,0};
int y[] = {0,0,1,0,-1};

int solve(int n,int m, int pre, int dir)
{
    int &ret = dp[n][m][pre][dir];
    if(ret != -1) return ret;

    ret = 0;
    int p, q, i, j;
    vector <pii> v;

    for(i=0;i<5;i++)
    {
        p = n + x[i];
        q = m + y[i];
        if(p>=0 && q>=0 && p<r && q<c && arr[p][q] == '1' && col[p][q] == 0)
        {
            col[p][q] = 1;
            ret++;
            v.push_back(MP(p,q));
        }
    }

    int tmp = inf;

    if(n+1 < r)
        tmp = solve(n+1, m, dir, 0);
    if(m+1 < c)
        tmp = min(tmp , solve(n, m+1, dir, 1));

    if(tmp == inf)
        tmp = 0;
    ret = ret + tmp;

    j = v.size();

    for(i=0;i<j;i++)
    {
        col[v[i].X][v[i].Y] = 0;
    }

    return ret;
}

int main()
{
    int t, n, m, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&r,&c);

        for(i=0;i<=r;i++)
            for(j=0;j<=c;j++)
                dp[i][j][0][0] = -1, dp[i][j][0][1] = -1, dp[i][j][1][0] = -1, dp[i][j][1][1] = -1, col[i][j] = 0;

        for(i=0;i<r;i++)
            scanf("%s",arr[i]);

        printf("%d\n",solve(0,0,0,0));
    }

    return 0;
}
/*
1
5 5
11111
11111
11111
11111
11111

ans = 16
*/
