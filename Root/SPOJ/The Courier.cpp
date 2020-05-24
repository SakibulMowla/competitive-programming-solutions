#include "bits/stdc++.h"
using namespace std;

#define SZ 110
#define SZ1 13

#define X first
#define Y second

#define MP(a, b) make_pair(a, b)

typedef pair <int , int> pii;
const int inf = 1<<28;

int n, b;
int dp[SZ][1<<SZ1];
int mat[SZ][SZ];
vector <pii> adj;

int solve(int cur, int mask)
{
//    printf("mask = %d\n",mask);
//    printf("cur = %d\n",cur);
    if(!mask)
        return mat[cur][b];

    int &ret = dp[cur][mask];

    if(ret != -1)
        return ret;

    int i, j, k, tmp;

    k = adj.size();
    ret = inf;

    for(i=0; i<k; i++)
    {
        if(mask&(1<<i))
        {
            tmp = mask&~(1<<i);
            j = mat[cur][adj[i].X];
            j += mat[adj[i].X][adj[i].Y];
            ret = min(ret, j+solve(adj[i].Y, tmp));
        }
    }

    return ret;
}

void process_and_floyd()
{
    int i, j, k, l, m, sum = 0;

    scanf("%d %d %d",&n,&m,&b);

    for(i=0; i<=n; i++)
    {
        for(j=i+1; j<=n; j++)
            mat[i][j] = mat[j][i] = inf;
        mat[i][i] = 0;
    }

    for(i=0; i<m; i++)
    {
        scanf("%d %d %d",&j,&k,&l);
        mat[j][k] = mat[k][j] = min(mat[j][k], l);
    }

    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

    ///Graph After Floyd-Warshall
//    for(i=1; i<=n; i++)
//    {
//        printf("i = %d  --->",i);
//        for(j=1; j<=n; j++)
//            printf(" %d",mat[i][j]);
//        printf("\n");
//    }

    scanf("%d",&m);
    adj.clear();

    for(i=0; i<m; i++)
    {
        scanf("%d %d %d",&j,&k,&l);
        sum += l;
        while(l--)
            adj.push_back(MP(j, k));
    }

//    printf("Size = %d\n",adj.size());

    k = (1<<sum) - 1;

//    for(i=0; i<=k; i++)
//        dp[i] = -1;
    memset(dp, -1, sizeof(dp));

    printf("%d\n",solve(b, k));
}

int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
        process_and_floyd();
    }

    return 0;
}
